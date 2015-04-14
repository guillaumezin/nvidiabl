/*
 * Backlight driver for Nvidia graphics adapters.
 *
 * Copyright (c) 2009-2011 Guillaume Zin <guillaume.zin@gmail.com>
 * Copyright (c) 2008-2009 Mario Schwalbe <schwalbe@inf.tu-dresden.de>
 * Based on the mechanism discovered by the author of NvClock:
 * Copyright (c) 2001-2009 Roderick Colenbrander
 *     Site: http://nvclock.sourceforge.net
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

/*
 * Maybe the check against the subsystem vendor should be removed,
 * but there's no guarantee that the chip's smartdimmer signals
 * are actually connected to the display logic. Right now, these
 * are the supported (read connected) vendors according to NvClock.
 */

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/backlight.h>
#include <linux/dmi.h>
#include <linux/err.h>

#include "nvidiabl-types.h"
#include "nvidiabl-models.h"

/* Check for the new backlight suspend/resume feature */
#if defined(BL_CORE_SUSPENDRESUME)
	#warning USE_BACKLIGHT_SUSPEND
	#define USE_BACKLIGHT_SUSPEND
/* Otherwise use a platform driver if PM is enabled */
#elif defined(CONFIG_PM)
	#warning USE_PLATFORM_DRIVER
	#define USE_PLATFORM_DRIVER
#endif

static unsigned long nvidiabl_ignore_device = 0;
static long off = NVIDIABL_UNSET;
static long min = NVIDIABL_UNSET;
static long max = NVIDIABL_UNSET;
static long screen_type = NVIDIABL_UNSET;
static unsigned long pci_id = PCI_ANY_ID;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,39)
/*
 * bl_type will receive the user's module parameter which will be matched against
 * the bl_types[] elements. Their indexes match the definitions
 * of 'enum backlight_type' in linux/backlight.h, making translating string into
 * enum value easy to do.
 */
#define BL_TYPE_SIZE 	10

struct backlight_type_id {
	char id[BL_TYPE_SIZE];
	enum backlight_type type;
};

static const struct backlight_type_id backlight_type_ids[] = { 
	{ "raw", BACKLIGHT_RAW },
	{ "platform", BACKLIGHT_PLATFORM },
	{ "firmware", BACKLIGHT_FIRMWARE }
};
  
static char bl_type[BL_TYPE_SIZE]= "raw";
module_param_string(type, bl_type, BL_TYPE_SIZE, 0644);
MODULE_PARM_DESC(type, "Backlight type (raw|platform|firmware) default is raw");
#endif

/*
 * DMI matching.
 * Used to ignore the wrong device on machines incorporating 2
 * graphics adapters, such as the Apple MacBook Pro 5.
 */
static int nvidiabl_wrong_dmi_match(const struct dmi_system_id *id)
{
        printk(KERN_INFO "nvidiabl: %s model detected in ignore tables\n", id->ident);
        nvidiabl_ignore_device = (unsigned long)id->driver_data;
        return 1;
}

static const struct dmi_system_id /* __initdata */ nvidiabl_ignore_table[] = {

#include "nvidiabl-ignore.h"

        /* end of list */
        { }
};

/*
 * DMI matching.
 * Used to autoload driver
 */
static int nvidiabl_dmi_match(const struct dmi_system_id *id)
{
        nvidiabl_descriptor *desc;
        printk(KERN_INFO "nvidiabl: %s model detected in DMI tables\n", id->ident);
        
        desc = (nvidiabl_descriptor *)(id->driver_data);
        
        pci_id = desc->pci_device_code;
        if (off == NVIDIABL_UNSET)
                off = desc->off;
        if (min == NVIDIABL_UNSET)
                min = desc->min;
        if (max == NVIDIABL_UNSET)
                max = desc->max;
	if (screen_type == NVIDIABL_UNSET)
		screen_type = desc->screen_type;
        return 1;
}

static const struct dmi_system_id /* __initdata */ nvidiabl_dmi_table[] = {
  
#include "nvidiabl-laptops.h"

        /* end of list */
        { }
};

/*
 * Driver data implementation
 */
static const struct pci_device_id *nvidiabl_match_id(struct pci_dev *dev)
{
	/* Search id in table */
	const struct pci_device_id *id = pci_match_id(nvidiabl_device_table, dev);

	return id;
}

static int nvidiabl_find_device(struct driver_data **dd, unsigned pci_device, unsigned ignore_device)
{
	struct pci_dev *dev = NULL;
	const struct pci_device_id *id;

	/* For each PCI device */
	while ((dev = pci_get_device(PCI_VENDOR_ID_NVIDIA, pci_device, dev))) {
		/* ... lookup id struct */
                id = nvidiabl_match_id(dev);
                if (id && (!ignore_device || (dev->device != ignore_device))) {
                        printk(KERN_INFO "nvidiabl: Supported Nvidia graphics"
                              " adapter %04x:%04x:%04x:%04x detected\n",
                              id->vendor, id->device,
                              dev->subsystem_vendor, dev->subsystem_device);

                        /* Setup driver data */
                        *dd = (struct driver_data *)id->driver_data;
                        (*dd)->dev = dev;
                        return 0;
                }
	}

	printk(KERN_ERR "nvidiabl: No supported Nvidia graphics adapter"
	       " found\n");
	return -ENODEV;
}

/*
 * Driver implementation
 */
static struct driver_data *driver_data = NULL;
static struct backlight_device *nvidiabl_device;

#ifdef USE_PLATFORM_DRIVER
static int nvidiabl_probe(struct platform_device *pdev)
#else
static int __init nvidiabl_init(void)
#endif
{
	int err;
	int iii;
        s64 calc;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34)
        struct backlight_properties props;
#endif
        
	/* Bail-out if PCI subsystem is not initialized */
	if (no_pci_devices())
		return -ENODEV;

	printk(KERN_INFO "nvidiabl: loading driver version " NVIDIABL_VERSION_STR "\n");
	
	/* Check DMI whether we need to ignore some device */
	dmi_check_system(nvidiabl_ignore_table);
        
        /* Check DMI whether we have a known system */
        dmi_check_system(nvidiabl_dmi_table);

        err = nvidiabl_find_device(&driver_data, pci_id, nvidiabl_ignore_device);
        if (err)
                return err;
        
        nvidiabl_force_model(&driver_data);

        if ((screen_type != NVIDIABL_DEFAULT) && (screen_type != NVIDIABL_UNSET))
                driver_data->screen_type = screen_type;
	
        /* Map smartdimmer */
	err = driver_data->map(driver_data);
	if (err)
		return err;
        
	/* Register at backlight framework */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34)
        memset(&props, 0, sizeof(struct backlight_properties));
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,39)
	
	for (iii = 0 ; iii < sizeof(backlight_type_ids) ; iii++) {
		if (strncasecmp(bl_type, backlight_type_ids[iii].id, sizeof(bl_type)) == 0) {
			props.type = backlight_type_ids[iii].type;
			printk(KERN_INFO "nvidiabl: backlight type is %s\n", backlight_type_ids[iii].id);
		}
	}
#endif
	nvidiabl_device = backlight_device_register("nvidia_backlight", NULL,
	                                             driver_data,
	                                             &driver_data->backlight_ops,
	                                             &props);
#else
        nvidiabl_device = backlight_device_register("nvidia_backlight", NULL,
                                                     driver_data,
                                                     &driver_data->backlight_ops);
#endif
                                                     
	if (IS_ERR(nvidiabl_device)) {
		driver_data->unmap(driver_data);
		return PTR_ERR(nvidiabl_device);
	}

        driver_data->backup(driver_data);

        if (max == NVIDIABL_UNSET) {
		driver_data->max = NVIDIABL_AUTO;
	}
	else if (max != NVIDIABL_DEFAULT) {
                driver_data->max = max;
	}
          
        if (driver_data->max == NVIDIABL_AUTO) {
                printk(KERN_INFO "nvidiabl: autodetecting maximum\n");
                driver_data->max = driver_data->autodetect(driver_data, T_NVIDIABL_MAX);
        }
        printk(KERN_INFO "nvidiabl: using value 0x%x as maximum\n", driver_data->max);

        
	if (off == NVIDIABL_UNSET) {
		driver_data->off = NVIDIABL_AUTO;
	}
	else if (off != NVIDIABL_DEFAULT) {
                driver_data->off = off;
	} 

        if (driver_data->off == NVIDIABL_AUTO) {
                printk(KERN_INFO "nvidiabl: autodetecting off\n");
                driver_data->off = driver_data->autodetect(driver_data, T_NVIDIABL_OFF);
        }
        
        if (driver_data->off < 0) {
                printk(KERN_INFO "nvidiabl: off is %d%% of maximum\n", -1 * driver_data->off);
                calc = driver_data->max * (-1 * driver_data->off);
                do_div(calc, 100);
                driver_data->off = calc;
        }
        printk(KERN_INFO "nvidiabl: using value 0x%x as off\n", driver_data->off);


        if (min == NVIDIABL_UNSET) {
                driver_data->min = NVIDIABL_AUTO;
        } 
        else if (min != NVIDIABL_DEFAULT) {
                driver_data->min = min;
        }

        if (driver_data->min == NVIDIABL_AUTO) {
                printk(KERN_INFO "nvidiabl: autodetecting minimum\n");
                driver_data->min = driver_data->autodetect(driver_data, T_NVIDIABL_MIN);
        }
        
        if (driver_data->min < 0) {
                printk(KERN_INFO "nvidiabl: minimum is %d%% of maximum\n", -1 * driver_data->min);
                calc = driver_data->max * (-1 * driver_data->min);
                do_div(calc, 100);
                driver_data->min = calc;
        }
        printk(KERN_INFO "nvidiabl: using value 0x%x as minimum\n", driver_data->min);
        
        
        /* Set up backlight device */
        nvidiabl_device->props.max_brightness = FB_BACKLIGHT_LEVELS - 1;
	nvidiabl_device->props.brightness =
		nvidiabl_device->ops->get_brightness(nvidiabl_device);
	backlight_update_status(nvidiabl_device);
	return 0;
}

#ifdef USE_PLATFORM_DRIVER
static int nvidiabl_remove(struct platform_device *pdev)
#else
static void __exit nvidiabl_exit(void)
#endif
{
        driver_data->restore(driver_data);
        
	/* Unregister at backlight framework */
	if (nvidiabl_device)
		backlight_device_unregister(nvidiabl_device);

	/* Unmap smartdimmer */
	driver_data->unmap(driver_data);

	/* Release PCI device */
	if (driver_data->dev)
		pci_dev_put(driver_data->dev);
#ifdef USE_PLATFORM_DRIVER
	return 0;
#endif
}

/*
 * Platform driver implementation
 */
#ifdef USE_PLATFORM_DRIVER

static int nvidiabl_resume(struct platform_device *pdev)
{
	backlight_update_status(nvidiabl_device);
	return 0;
}

static struct platform_driver nvidiabl_driver = {
	.probe          = nvidiabl_probe,
	.remove         = nvidiabl_remove,
	.resume         = nvidiabl_resume,
	.driver         = {
		.owner  = THIS_MODULE,
		.name   = "nvidiabl"
	},
};

static struct platform_device *nvidiabl_platform_device;

static int __init nvidiabl_init(void)
{
	int err;
	
	err = platform_driver_register(&nvidiabl_driver);
	if (err)
		return err;

	nvidiabl_platform_device =
		platform_device_register_simple("nvidiabl", -1, NULL, 0);
	if (!nvidiabl_platform_device) {
		platform_driver_unregister(&nvidiabl_driver);
		return -ENOMEM;
	}

	return 0;
}

static void __exit nvidiabl_exit(void)
{
	platform_device_unregister(nvidiabl_platform_device);
	platform_driver_unregister(&nvidiabl_driver);
}

#endif /* USE_PLATFORM_DRIVER */

module_init(nvidiabl_init);
module_exit(nvidiabl_exit);

MODULE_AUTHOR("Mario Schwalbe <schwalbe@inf.tu-dresden.de>, Guillaume Zin <guillaume.zin@gmail.com>");
MODULE_DESCRIPTION("Nvidia-based graphics adapter backlight driver");
MODULE_LICENSE("GPL");

MODULE_DEVICE_TABLE(dmi, nvidiabl_dmi_table);

module_param_named(off, off, long, 0644);
MODULE_PARM_DESC(off, "value to put in the register to disable the backlight, negative value is interpreted as percentage of maximum, -101 for default, autodetect otherwise");

module_param_named(min, min, long, 0644);
MODULE_PARM_DESC(min, "minimum register value for the backlight, negative value is interpreted as percentage of maximum, -101 for default, autodetect otherwise");

module_param_named(max, max, long, 0644);
MODULE_PARM_DESC(max, "maximum register value for the backlight, -101 for default, autodetect otherwise");

module_param_named(screen_type, screen_type, long, 0644);
MODULE_PARM_DESC(max, "screen type, 0 for default, 1 for auto, 2 to force LVDS, 3 to force EPD");

module_param_named(pci_id, pci_id, ulong, 0644);
MODULE_PARM_DESC(pci_id, "PCI ID of the Nvidia card - usefull only when not using autodetection and more than one Nvidia PCI device");
