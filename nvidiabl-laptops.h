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
 * Fourth argument is the value to select register to adjust backlight
 *      NVIDIABL_SC_DEFAULT to use default value
 *      NVIDIABL_SC_AUTO for autodetect
 *      NVIDIABL_SC_LVDS to force LVDS register
 *      NVIDIABL_SC_EPD to force EPD register 
 * Fifth argument is the value to disable the backlight, it is 0 usually:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 *      negative value for percentage of maximum value (eg.: -10 for 10% of maximum value)
 * Sixth is minimum backlight value:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 *      negative value for percentage of maximum value (eg.: -10 for 10% of maximum value)
 * Seventh is maximum backlight value:
 *      NVIDIABL_DEFAULT to use default value
 *      NVIDIABL_AUTO for autodetect
 *      positive value for absolute register value
 */

NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-AW11", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-AW290J", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ11", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ31", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ38", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x1FFFF),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW2", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x1FFFF),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x679a),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-S560", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCF1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Inspiron 1370", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Vostro 3400", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Vostro 3500", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Latitude E6530", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 128000),

NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "N510", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "SR70S/SR71S", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "Q430/Q530", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x1df67),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "R510/P510", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "RV409/RV509/RV709", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "RV420/RV520/RV720/E3530/S3530/E3420/E3520", PCI_ANY_ID, NVIDIABL_SC_AUTO, 0, 0x52e, 0x679a),

NVIDIABL_DECLARE_LAPTOP_MODEL("TOSHIBA", "SATELLITE PRO U500", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("TOSHIBA", "SATELLITE L750", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("TOSHIBA", "SATELLITE L755", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook5,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, 0, 1000),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook5,2", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook6,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBook7,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro3,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro3,2", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro4,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,2", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,4", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,5", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookPro7,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir2,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir3,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "MacBookAir3,2", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Apple Inc.", "iMac10,1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x239),

NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "4313CTO", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "4270CTO", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "42844MG", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "9523", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "20192", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x1e848),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "QIQY5", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x7000),
NVIDIABL_DECLARE_LAPTOP_MODEL("LENOVO", "20193", PCI_ANY_ID, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x20f58),

NVIDIABL_DECLARE_LAPTOP_MODEL("LG Electronics", "R590-P.BN58P1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LG Electronics", "R590-K.BE52P1", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("LG Electronics", "R580-K.AHC4WA9", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("ASUSTeK COMPUTER INC.", "G75VW", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("ASUSTeK COMPUTER INC.", "G75VX", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x20000),
NVIDIABL_DECLARE_LAPTOP_MODEL("ASUSTeK Computer Inc.", "G74Sx", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("ASUSTeK Computer Inc.", "G55VW", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("ASUSTeK COMPUTER INC.", "G55VW", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Compal", "PBL01", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
NVIDIABL_DECLARE_LAPTOP_MODEL("Compal", "QAL51", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 135000),

NVIDIABL_DECLARE_LAPTOP_MODEL("Quanta", "TW9", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("FUJITSU", "AMILO Pi 3560", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),

NVIDIABL_DECLARE_LAPTOP_MODEL("Acer", "TravelMate 8481TG", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, 0x08000),

NVIDIABL_DECLARE_LAPTOP_MODEL("Hewlett-Packard", "HP Pavilion dv3500 Notebook PC", PCI_ANY_ID, NVIDIABL_SC_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO, NVIDIABL_AUTO),
