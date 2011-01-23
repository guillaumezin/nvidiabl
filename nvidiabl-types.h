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

#define NVIDIABL_DEFAULT        -101
#define NVIDIABL_AUTO           -102
#define NVIDIABL_UNSET          -103

#define NVIDIABL_AUTO_OFF       0
#define NVIDIABL_AUTO_MIN       -5

typedef enum { T_NVIDIABL_OFF, T_NVIDIABL_MIN, T_NVIDIABL_MAX } T_NVIDIABL_VAL;

/* Driver private data structure */
struct driver_data {
        /* PCI region (BAR) the smartdimmer register is in */
        unsigned bar;
        /* Register offset into this region */
        unsigned long reg_offset;
        /* Register size in byte */
        unsigned reg_size;

        /* off, min and max value for intensity in register */
        int off, min, max;
        
        /* register backup and restore */
        unsigned backup_value;
        unsigned (*backup)(struct driver_data *);
        unsigned (*restore)(struct driver_data *);
        unsigned (*autodetect)(struct driver_data *, T_NVIDIABL_VAL which);

        /* Backlight operations structure */
        struct backlight_ops backlight_ops;

        /* The device we drive */
        struct pci_dev *dev;
        /* Pointer to the mapped smartdimmer register */
        /* volatile */ void __iomem *smartdimmer;
};

typedef struct {
        unsigned long pci_device_code;
        int off;
        int min;
        int max;  
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

#define NVIDIABL_DECLARE_GPU_MODEL(pci_device_code, algorithm) \
    {\
        PCI_VDEVICE(NVIDIA, pci_device_code), \
        (kernel_ulong_t)&algorithm \
    }

#endif