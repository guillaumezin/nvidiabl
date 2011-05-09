/*
 * DMI list of laptops to use with this module with the associated
 * PCI device to identify the Nvidia GPU and backlight settings.
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
 * First argument comes from "cat /sys/class/dmi/id/sys_vendor"
 * Second argument comes from "cat /sys/class/dmi/id/product_name" (it can be the beginning of the string only to cover more than one model)
 * Third argument comes from "lspci -nn | grep nVidia", last four hex digits
 *      for instance "01:00.0 VGA compatible controller [0300]: nVidia Corporation G98 [GeForce 9300M GS] [10de:06e9] (rev a1)" gives 0x06e9
 *      obtained number must be listed in "nvidiabl-gpu.h"
 *      you can use PCI_ANY_ID to autodetect GPU
 * Fourth argument is the value to disable the backlight, it is 0 usually:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 *      negative value for percentage of maximum value (eg.: -10 for 10% of maximum value)
 * Fifth is minimum backlight value:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 *      negative value for percentage of maximum value (eg.: -10 for 10% of maximum value)
 * Sixth is maximum backlight value:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 */

NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-AW11", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ11", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ38", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW2", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-S560", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCF1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Inspiron 1370", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Vostro 3500", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x7000),

NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "N510", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "SR70S/SR71S", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("TOSHIBA", "SATELLITE PRO U500", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook5,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook5,2", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook6,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook7,1", PCI_ANY_ID, NVIDIABL_AUTO, 0, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro3,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro3,2", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro4,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,2", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,3", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,4", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,5", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro7,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir2,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir3,1", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir3,2", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

