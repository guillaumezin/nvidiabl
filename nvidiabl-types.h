#ifndef NVIDIABL_TYPE_H
#define NVIDIABL_TYPE_H

#include <linux/pci.h>
#include <linux/fb.h>

/* Driver private data structure */
struct driver_data {
        /* PCI region (BAR) the smartdimmer register is in */
        unsigned bar;
        /* Register offset into this region */
        unsigned long reg_offset;
        /* Register size in byte */
        unsigned reg_size;

        /* off, min and max value for intensity in register */
        unsigned off, min, max;

        /* Backlight operations structure */
        struct backlight_ops backlight_ops;

        /* The device we drive */
        struct pci_dev *dev;
        /* Pointer to the mapped smartdimmer register */
        /* volatile */ void __iomem *smartdimmer;
};

typedef struct {
        unsigned long pci_device_code;
        long off;
        long min;
        long max;  
} nvidiabl_descriptor;

#define NVIDIABL_DECLARE_LAPTOP_MODEL(sys_vendor, product_name, pci_device_code, off_value, min_value, max_value) \
    {\
        .callback       = &nvidiabl_dmi_match,\
        .ident          = sys_vendor " - " product_name,\
        .matches        = {\
            DMI_MATCH(DMI_SYS_VENDOR, sys_vendor),\
            DMI_MATCH(DMI_PRODUCT_NAME, product_name),\
        },\
        .driver_data    = (void *)&(nvidiabl_descriptor){pci_device_code, off_value, min_value, max_value} \
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

#endif