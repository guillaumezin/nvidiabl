/*
 * DMI list of laptops not to use with this module.
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
 */

/* This driver has no effect on the backlight for the following models */
NVIDIABL_IGNORE_LAPTOP_MODEL("Apple Inc.", "MacBookPro6,1", PCI_ANY_ID),
NVIDIABL_IGNORE_LAPTOP_MODEL("Apple Inc.", "MacBookPro6,2", PCI_ANY_ID),

