/*
 * Nvidia mobile GPU list with associated intensity algorithm.
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
 * First argument comes from "lspci -nn | grep nVidia", last four hex digits
 *      for instance "01:00.0 VGA compatible controller [0300]: nVidia Corporation G98 [GeForce 9300M GS] [10de:06e9] (rev a1)" gives 0x06e9
 * Second argument is the algortihm name that comes from nvidiabl-models.c (currently nv4x_driver_data or nv5x_driver_data)
 */

/* nVidia Geforce Go 7800GTX */
NVIDIABL_DECLARE_GPU_MODEL(0x0099, nv4x_driver_data),
/* nVidia Geforce Go 6800 */
NVIDIABL_DECLARE_GPU_MODEL(0x00c8, nv4x_driver_data),
/* nVidia Geforce Go 6800Ultra */
NVIDIABL_DECLARE_GPU_MODEL(0x00c9, nv4x_driver_data),
/* nVidia QuadroFX Go 1400 */
NVIDIABL_DECLARE_GPU_MODEL(0x00cc, nv4x_driver_data),
/* nVidia Geforce Go 6600 */
NVIDIABL_DECLARE_GPU_MODEL(0x0144, nv4x_driver_data),
/* nVidia GeForce Go 6600TE/6200TE */
NVIDIABL_DECLARE_GPU_MODEL(0x0146, nv4x_driver_data),
/* nVidia Geforce Go 6600 */
NVIDIABL_DECLARE_GPU_MODEL(0x0148, nv4x_driver_data),
/* nVidia Geforce Go 6600GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0149, nv4x_driver_data),
/* nVidia Geforce Go 6200 */
NVIDIABL_DECLARE_GPU_MODEL(0x0164, nv4x_driver_data),
/* nVidia Geforce Go 6400 */
NVIDIABL_DECLARE_GPU_MODEL(0x0166, nv4x_driver_data),
/* nVidia Geforce Go 6200 */
NVIDIABL_DECLARE_GPU_MODEL(0x0167, nv4x_driver_data),
/* nVidia Geforce Go 6400 */
NVIDIABL_DECLARE_GPU_MODEL(0x0168, nv4x_driver_data),
/* nVidia Geforce Go 7300 */
NVIDIABL_DECLARE_GPU_MODEL(0x01d7, nv4x_driver_data),
/* nVidia Geforce Go 7400 */
NVIDIABL_DECLARE_GPU_MODEL(0x01d8, nv4x_driver_data),
/* nVidia Geforce Go 7400GS */
NVIDIABL_DECLARE_GPU_MODEL(0x01d9, nv4x_driver_data),
/* nVidia Quadro NVS 110M */
NVIDIABL_DECLARE_GPU_MODEL(0x01da, nv4x_driver_data),
/* nVidia Quadro NVS 120M */
NVIDIABL_DECLARE_GPU_MODEL(0x01db, nv4x_driver_data),
/* nVidia QuadroFX 350M */
NVIDIABL_DECLARE_GPU_MODEL(0x01dc, nv4x_driver_data),
/* nVidia Geforce 7500LE */
NVIDIABL_DECLARE_GPU_MODEL(0x01dd, nv4x_driver_data),
/* NV44M */
NVIDIABL_DECLARE_GPU_MODEL(0x0228, nv4x_driver_data),
/* nVidia Geforce Go 7950GTX */
NVIDIABL_DECLARE_GPU_MODEL(0x0297, nv4x_driver_data),
/* nVidia Geforce Go 7900GS */
NVIDIABL_DECLARE_GPU_MODEL(0x0298, nv4x_driver_data),
/* nVidia Geforce Go 7900GTX */
NVIDIABL_DECLARE_GPU_MODEL(0x0299, nv4x_driver_data),
/* nVidia QuadroFX 2500M */
NVIDIABL_DECLARE_GPU_MODEL(0x029a, nv4x_driver_data),
/* nVidia QuadroFX 1500M */
NVIDIABL_DECLARE_GPU_MODEL(0x029b, nv4x_driver_data),
/* nVidia Geforce Go 7700 */
NVIDIABL_DECLARE_GPU_MODEL(0x0397, nv4x_driver_data),
/* nVidia Geforce Go 7600 */
NVIDIABL_DECLARE_GPU_MODEL(0x0398, nv4x_driver_data),
/* nVidia Geforce Go 7600GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0399, nv4x_driver_data),
/* nVidia Quadro NVS 300M */
NVIDIABL_DECLARE_GPU_MODEL(0x039a, nv4x_driver_data),
/* nVidia Geforce Go 7900SE */
NVIDIABL_DECLARE_GPU_MODEL(0x039b, nv4x_driver_data),
/* nVidia QuadroFX 550M */
NVIDIABL_DECLARE_GPU_MODEL(0x039c, nv4x_driver_data),
/* nVidia Geforce 9500M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x0405, nv5x_driver_data),
/* nVidia Geforce NB9P-GE */
NVIDIABL_DECLARE_GPU_MODEL(0x0406, nv5x_driver_data),
/* nVidia Geforce 8600M GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0407, nv5x_driver_data),
/* nVidia Geforce 8600M GTS */
NVIDIABL_DECLARE_GPU_MODEL(0x0408, nv5x_driver_data),
/* nVidia Geforce 8700M GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0409, nv5x_driver_data),
/* nVidia Quadro NVS 370M */
NVIDIABL_DECLARE_GPU_MODEL(0x040a, nv5x_driver_data),
/* nVidia Quadro NVS 320M */
NVIDIABL_DECLARE_GPU_MODEL(0x040b, nv5x_driver_data),
/* nVidia QuadroFX 570M */
NVIDIABL_DECLARE_GPU_MODEL(0x040c, nv5x_driver_data),
/* nVidia QuadroFX 1600M */
NVIDIABL_DECLARE_GPU_MODEL(0x040d, nv5x_driver_data),
/* nVidia Geforce 8600M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x0425, nv5x_driver_data),
/* nVidia Geforce 8400M GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0426, nv5x_driver_data),
/* nVidia Geforce 8400M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x0427, nv5x_driver_data),
/* nVidia Geforce 8400M G */
NVIDIABL_DECLARE_GPU_MODEL(0x0428, nv5x_driver_data),
/* nVidia Quadro NVS 140M */
NVIDIABL_DECLARE_GPU_MODEL(0x0429, nv5x_driver_data),
/* nVidia Quadro NVS 130M */
NVIDIABL_DECLARE_GPU_MODEL(0x042a, nv5x_driver_data),
/* nVidia Quadro NVS 135M */
NVIDIABL_DECLARE_GPU_MODEL(0x042b, nv5x_driver_data),
/* nVidia Quadro FX 360M */
NVIDIABL_DECLARE_GPU_MODEL(0x042d, nv5x_driver_data),
/* nVidia Geforce 9300M G */
NVIDIABL_DECLARE_GPU_MODEL(0x042e, nv5x_driver_data),
/* nVidia Geforce 8800M GTS */
NVIDIABL_DECLARE_GPU_MODEL(0x0609, nv5x_driver_data),
/* nVidia Geforce 8800M GTX */
NVIDIABL_DECLARE_GPU_MODEL(0x060c, nv5x_driver_data),
/* nVidia QuadroFX 3600M */
NVIDIABL_DECLARE_GPU_MODEL(0x061c, nv5x_driver_data),
/* nVidia Geforce 9600M GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0647, nv5x_driver_data),
/* nVidia Geforce 9600M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x0648, nv5x_driver_data),
/* nVidia Geforce 9600M GT */
NVIDIABL_DECLARE_GPU_MODEL(0x0649, nv5x_driver_data),
/* nVidia Geforce 9500M G */
NVIDIABL_DECLARE_GPU_MODEL(0x064b, nv5x_driver_data),
/* nVidia Geforce 9300M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x06e5, nv5x_driver_data),
/* nVidia Geforce 9200M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x06e8, nv5x_driver_data),
/* nVidia Geforce 9300M GS */
NVIDIABL_DECLARE_GPU_MODEL(0x06e9, nv5x_driver_data),
/* nVidia Quadro NVS 150M */
NVIDIABL_DECLARE_GPU_MODEL(0x06ea, nv5x_driver_data),
/* nVidia Quadro NVS 160M */
NVIDIABL_DECLARE_GPU_MODEL(0x06eb, nv5x_driver_data),
/* nVidia Geforce G105M */
NVIDIABL_DECLARE_GPU_MODEL(0x06ec, nv5x_driver_data),
/* nVidia QuadroFX 370M */
NVIDIABL_DECLARE_GPU_MODEL(0x06fb, nv5x_driver_data),
/* nVidia Geforce 9400M */
NVIDIABL_DECLARE_GPU_MODEL(0x0863, nv5x_driver_data),
/* NVIDIA GeForce 9400M */
NVIDIABL_DECLARE_GPU_MODEL(0x0870, nv5x_driver_data),
/* NVIDIA GeForce 9200 */
NVIDIABL_DECLARE_GPU_MODEL(0x0871, nv5x_driver_data),
/* NVIDIA GeForce G102M */
NVIDIABL_DECLARE_GPU_MODEL(0x0872, nv5x_driver_data),
/* NVIDIA GeForce G102M */
NVIDIABL_DECLARE_GPU_MODEL(0x0873, nv5x_driver_data),
/* NVIDIA Quadro FX 470 */
NVIDIABL_DECLARE_GPU_MODEL(0x087a, nv5x_driver_data),
/* NVIDIA Quadro FX 470 */
NVIDIABL_DECLARE_GPU_MODEL(0x087f, nv5x_driver_data),
/* NVIDIA GeForce 210M */
NVIDIABL_DECLARE_GPU_MODEL(0x0a74, nv5x_driver_data),
/* NVIDIA GeForce 230M */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2a, nv5x_driver_data),
/* nVidia Geforce 305M */
NVIDIABL_DECLARE_GPU_MODEL(0x0a69, nv5x_driver_data),
/* NVIDIA GeForce 310M */
NVIDIABL_DECLARE_GPU_MODEL(0x0a75, nv5x_driver_data),
/* NVIDIA GeForce 330M */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2b, nv5x_driver_data),