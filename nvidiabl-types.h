/*
 * Struct and macros for Nvidia backlight module.
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

#ifndef NVIDIABL_TYPE_H
#define NVIDIABL_TYPE_H

#include <linux/pci.h>
#include <linux/fb.h>
#include <linux/moduleparam.h>

#define NVIDIABL_STR_1(s) #s
#define NVIDIABL_STR(s) NVIDIABL_STR_1(s)
#define NVIDIABL_VERSION_STR NVIDIABL_STR(NVIDIABL_VERSION)

#define NVIDIABL_DEFAULT        -101
#define NVIDIABL_AUTO           -102
#define NVIDIABL_UNSET          -103

#define NVIDIABL_SC_DEFAULT     0
#define NVIDIABL_SC_AUTO        1
#define NVIDIABL_SC_LVDS        2
#define NVIDIABL_SC_EPD         3

#define NVIDIABL_AUTO_OFF       0
#define NVIDIABL_AUTO_MIN       -5

typedef enum { T_NVIDIABL_OFF, T_NVIDIABL_MIN, T_NVIDIABL_MAX } T_NVIDIABL_VAL;

/* Driver private data structure */
struct driver_data {
        /* PCI region (BAR) the smartdimmer register is in */
        unsigned bar;
        /* Register offset into this region */
        unsigned long reg_offset1;
        unsigned long reg_offset2;
        /* Register size in byte */
        unsigned reg_size;

        /* off, min and max value for intensity in register */
        int off, min, max;
	
	/* depending on screen_type, we may have to choose which register to read and write */
	int screen_type;
        
        /* register backup and restore */
        unsigned backup_value;
        void (*backup)(struct driver_data *);
        void (*restore)(struct driver_data *);
        unsigned (*autodetect)(struct driver_data *, T_NVIDIABL_VAL which);
	
	int (*map)(struct driver_data *dd);
	void (*unmap)(struct driver_data *dd);

        /* Backlight operations structure */
        struct backlight_ops backlight_ops;

        /* The device we drive */
        struct pci_dev *dev;
        /* Pointer to the mapped smartdimmer register */
        /* volatile */ void __iomem *smartdimmer;
};

typedef struct {
        unsigned long pci_device_code;
	int screen_type;
        int off;
        int min;
        int max;  
} nvidiabl_descriptor;

#define NVIDIABL_DECLARE_LAPTOP_MODEL(sys_vendor, product_name, pci_device_code, screen_type, off_value, min_value, max_value) \
    {\
        .callback       = &nvidiabl_dmi_match,\
        .ident          = sys_vendor " - " product_name,\
        .matches        = {\
            DMI_MATCH(DMI_SYS_VENDOR, sys_vendor),\
            DMI_MATCH(DMI_PRODUCT_NAME, product_name),\
        },\
        .driver_data    = (void *)&(nvidiabl_descriptor){pci_device_code, screen_type, off_value, min_value, max_value} \
}

#define NVIDIABL_IGNORE_LAPTOP_MODEL(sys_vendor, product_name, pci_device_code) \
    {\
        .callback       = &nvidiabl_wrong_dmi_match,\
        .ident          = sys_vendor " - " product_name,\
        .matches        = {\
            DMI_MATCH(DMI_SYS_VENDOR, sys_vendor),\
            DMI_MATCH(DMI_PRODUCT_NAME, product_name),\
        },\
        .driver_data    = (void *)pci_device_code \
}

#define NVIDIABL_DECLARE_GPU_MODEL(pci_device_code, algorithm) \
    {\
        PCI_VDEVICE(NVIDIA, pci_device_code), \
        (kernel_ulong_t)&algorithm \
    }

#endif
