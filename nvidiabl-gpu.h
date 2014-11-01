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

/* Geforce Go 7800 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0098, nv4x_driver_data),
/* Geforce Go 7800 GTX (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0099, nv4x_driver_data),
/* Geforce Go 6800 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x00c8, nv4x_driver_data),
/* Geforce Go 6800 Ultra (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x00c9, nv4x_driver_data),
/* Geforce Go 6600 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0144, nv4x_driver_data),
/* Geforce Go 6600 TE/6200 TE (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0146, nv4x_driver_data),
/* Geforce Go 6600 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0148, nv4x_driver_data),
/* Geforce Go 6600 GT (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0149, nv4x_driver_data),
/* Geforce Go 6200 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0164, nv4x_driver_data),
/* Geforce Go 6400 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0166, nv4x_driver_data),
/* Geforce Go 6200 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0167, nv4x_driver_data),
/* Geforce Go 6400 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0168, nv4x_driver_data),
/* Geforce Go 7200 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01d6, nv4x_driver_data),
/* Geforce Go 7300 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01d7, nv4x_driver_data),
/* Geforce Go 7400 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01d8, nv4x_driver_data),
/* Geforce Go 7400GS (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x01d9, nv4x_driver_data),
/* Geforce 7500 LE (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01dd, nv4x_driver_data),
/* NV44M (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0228, nv4x_driver_data),
/* Geforce Go 6150 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0244, nv4x_driver_data),
/* Geforce Go 6100 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0247, nv4x_driver_data),
/* Geforce Go 7950 GTX (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0297, nv4x_driver_data),
/* Geforce Go 7900 GS (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0298, nv4x_driver_data),
/* Geforce Go 7700 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0397, nv4x_driver_data),
/* Geforce Go 7600 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0398, nv4x_driver_data),
/* Geforce Go 7600 GT (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0399, nv4x_driver_data),
/* Geforce Go 7900SE (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x039b, nv4x_driver_data),
/* Geforce 9500M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0405, nv5x_driver_data),
/* Geforce NB9P-GE (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0406, nv5x_driver_data),
/* Geforce 8600M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0407, nv5x_driver_data),
/* Geforce 9650M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0408, nv5x_driver_data),
/* Geforce 8700M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0409, nv5x_driver_data),
/* Geforce 8600M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0425, nv5x_driver_data),
/* Geforce 8400M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0426, nv5x_driver_data),
/* Geforce 8400M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0427, nv5x_driver_data),
/* Geforce 8400M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0428, nv5x_driver_data),
/* Geforce 9300M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x042e, nv5x_driver_data),
/* Geforce 7150M / nForce 630M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0531, nv5x_driver_data),
/* Geforce 7000M / nForce 610M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0533, nv5x_driver_data),
/* Geforce 9800M GTX (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0608, nv5x_driver_data),
/* Geforce 8800M GTS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0609, nv5x_driver_data),
/* Geforce GTX 280M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x060a, nv5x_driver_data),
/* Geforce 9800M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x060b, nv5x_driver_data),
/* Geforce 8800M GTX (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x060c, nv5x_driver_data),
/* Geforce GTX 285M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x060f, nv5x_driver_data),
/* Geforce 9800M GTX (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0617, nv5x_driver_data),
/* Geforce GTX 260M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0618, nv5x_driver_data),
/* Geforce 9800M GTS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0628, nv5x_driver_data),
/* Geforce 9700M GTS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x062a, nv5x_driver_data),
/* Geforce 9800M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x062b, nv5x_driver_data),
/* Geforce 9800M GTS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x062c, nv5x_driver_data),
/* Geforce GTS 160M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0631, nv5x_driver_data),
/* Geforce GTS 150M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0632, nv5x_driver_data),
/* Geforce 9600M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0647, nv5x_driver_data),
/* Geforce 9600M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0648, nv5x_driver_data),
/* Geforce 9600M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0649, nv5x_driver_data),
/* Geforce 9700M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x064a, nv5x_driver_data),
/* Geforce 9500M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x064b, nv5x_driver_data),
/* Geforce 9650M GT (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x064c, nv5x_driver_data),
/* Geforce G 110M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0651, nv5x_driver_data),
/* Geforce GT 130M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0652, nv5x_driver_data),
/* Geforce GT 120M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0653, nv5x_driver_data),
/* Geforce GT 220M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0654, nv5x_driver_data),
/* Geforce 9650S (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0656, nv5x_driver_data),
/* Geforce 9400GT (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x065b, nv5x_driver_data),
/* Geforce GTX 480M (256.53) */
NVIDIABL_DECLARE_GPU_MODEL(0x06ca, nv5x_driver_data),
/* Geforce 9300M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06e5, nv5x_driver_data),
/* Geforce 9200M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06e8, nv5x_driver_data),
/* Geforce 9300M GS (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06e9, nv5x_driver_data),
/* Geforce G 105M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06ec, nv5x_driver_data),
/* Geforce G 103M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06ef, nv5x_driver_data),
/* Geforce G 105M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06f1, nv5x_driver_data),
/* Geforce 9100M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0844, nv5x_driver_data),
/* Geforce 8200M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0845, nv5x_driver_data),
/* Geforce 9400M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0862, nv5x_driver_data),
/* Geforce 9400M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0863, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0865, nv5x_driver_data),
/* Geforce 9400M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0866, nv5x_driver_data),
/* Geforce 9400 */
NVIDIABL_DECLARE_GPU_MODEL(0x0869, nv5x_driver_data),
/* Geforce 9100M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x086e, nv5x_driver_data),
/* Geforce 8200M G (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x086f, nv5x_driver_data),
/* Geforce 9400M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0870, nv5x_driver_data),
/* Geforce 9200 (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0871, nv5x_driver_data),
/* Geforce G 102M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0872, nv5x_driver_data),
/* Geforce G 102M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0873, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0874, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0876, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x087d, nv5x_driver_data),
/* ION LE (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x087e, nv5x_driver_data),
/* ION LE (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x087f, nv5x_driver_data),
/* Geforce 320M (User report) */
NVIDIABL_DECLARE_GPU_MODEL(0x08a0, nv5x_driver_data),
/* Geforce 320M (User report) */
NVIDIABL_DECLARE_GPU_MODEL(0x08a2, nv5x_driver_data),
/* Geforce 320M (User report) */
NVIDIABL_DECLARE_GPU_MODEL(0x08a3, nv5x_driver_data),
/* Geforce 320M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x08a5, nv5x_driver_data),
/* Geforce GT 230M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a28, nv5x_driver_data),
/* Geforce GT 330M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a29, nv5x_driver_data),
/* Geforce GT 230M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2a, nv5x_driver_data),
/* Geforce GT 330M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2b, nv5x_driver_data),
/* Geforce GT 320M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2d, nv5x_driver_data),
/* Geforce GT 240M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a34, nv5x_driver_data),
/* Geforce GT 325M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a35, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a64, nv5x_driver_data),
/* Geforce G 105M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a68, nv5x_driver_data),
/* Geforce G 105M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a69, nv5x_driver_data),
/* NVS 2100M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6a, nv5x_driver_data),
/* NVS 3100M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6c, nv5x_driver_data),
/* Geforce 305M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6e, nv5x_driver_data),
/* ION (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6f, nv5x_driver_data),
/* Geforce 310M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a70, nv5x_driver_data),
/* Geforce 305M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a71, nv5x_driver_data),
/* Geforce 310M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a72, nv5x_driver_data),
/* Geforce 305M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a73, nv5x_driver_data),
/* Geforce G 210M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a74, nv5x_driver_data),
/* Geforce 310M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a75, nv5x_driver_data),
/* Geforce 315M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a7a, nv5x_driver_data),
/* Geforce GTS 260M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ca8, nv5x_driver_data),
/* Geforce GTS 250M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ca9, nv5x_driver_data),
/* Geforce GT 335M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0caf, nv5x_driver_data),
/* Geforce GTS 350M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0cb0, nv5x_driver_data),
/* Geforce GTS 360M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0cb1, nv5x_driver_data),
/* GeForce GT 555M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dcd, nv5x_driver_data),
/* GeForce GTX 460M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dd1, nv5x_driver_data),
/* GeForce GT 445M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dd2, nv5x_driver_data),
/* GeForce GT 550M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dd6, nv5x_driver_data),
/* GeForce GT 635M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0de3, nv5x_driver_data),
/* GeForce GT 620M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0de8, nv5x_driver_data),
/* GeForce GT 630M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0de9, nv5x_driver_data),
/* GeForce GT 610M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dea, nv5x_driver_data),
/* GeForce GT 555M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0deb, nv5x_driver_data),
/* GeForce GT 525M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dec, nv5x_driver_data),
/* GeForce GT 520M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ded, nv5x_driver_data),
/* GeForce GT 415M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dee, nv5x_driver_data),
/* GeForce GT 425M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df0, nv5x_driver_data),
/* GeForce GT 420M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df1, nv5x_driver_data),
/* GeForce GT 435M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df2, nv5x_driver_data),
/* GeForce GT 420M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df3, nv5x_driver_data),
/* GeForce GT 540M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df4, nv5x_driver_data),
/* GeForce GT 525M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df5, nv5x_driver_data),
/* GeForce GT 550M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df6, nv5x_driver_data),
/* GeForce GT 520M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df7, nv5x_driver_data),
/* GeForce GT 470M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0e30, nv5x_driver_data),
/* GeForce GTX 485M LE (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0e31, nv5x_driver_data),
/* GeForce GT 755M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fcd, nv5x_driver_data),
/* GeForce GT 640M LE (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fce, nv5x_driver_data),
/* GeForce GT 650M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd1, nv5x_driver_data),
/* GeForce GT 640M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd2, nv5x_driver_data),
/* GeForce GT 640M LE (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd3, nv5x_driver_data),
/* GeForce GTX 660M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd4, nv5x_driver_data),
/* GeForce GT 650M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd5, nv5x_driver_data),
/* GeForce GT 640M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd8, nv5x_driver_data),
/* GeForce GT 645M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fd9, nv5x_driver_data),
/* GeForce GT 740M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fdf, nv5x_driver_data),
/* GeForce GTX 660M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe0, nv5x_driver_data),
/* GeForce GT 730M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe1, nv5x_driver_data),
/* GeForce GT 745M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe2, nv5x_driver_data),
/* GeForce GT 745M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe3, nv5x_driver_data),
/* GeForce GT 750M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe4, nv5x_driver_data),
/* GeForce GT 750M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe9, nv5x_driver_data),
/* GeForce GTX 660M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fe8, nv5x_driver_data),
/* GeForce GT 755M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0fea, nv5x_driver_data),
/* GeForce GT 520M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x1050, nv5x_driver_data),
/* GeForce GT 520MX (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1051, nv5x_driver_data),
/* GeForce GT 520M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1052, nv5x_driver_data),
/* GeForce 410M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1054, nv5x_driver_data),
/* GeForce 410M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x1055, nv5x_driver_data),
/* GeForce 610M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1058, nv5x_driver_data),
/* GeForce 610M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1059, nv5x_driver_data),
/* GeForce 610M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x105a, nv5x_driver_data),
/* GeForce 705M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x105b, nv5x_driver_data),
/* GeForce GT 620M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1140, nv5x_driver_data),
/* GeForce GTX 775M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x119d, nv5x_driver_data),
/* GeForce GTX 780M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x119e, nv5x_driver_data),
/* GeForce GTX 780M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x119f, nv5x_driver_data),
/* GeForce GTX 680M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11a0, nv5x_driver_data),
/* GeForce GTX 670MX (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11a1, nv5x_driver_data),
/* GeForce GTX 675MX (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11a2, nv5x_driver_data),
/* GeForce GTX 680MX (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11a3, nv5x_driver_data),
/* GeForce GTX 675MX (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11a7, nv5x_driver_data),
/* GeForce GTX 770M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11e0, nv5x_driver_data),
/* GeForce GTX 765M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11e1, nv5x_driver_data),
/* GeForce GTX 765M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11e2, nv5x_driver_data),
/* GeForce GTX 760M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11e3, nv5x_driver_data),
/* GeForce GTX 570M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1210, nv5x_driver_data),
/* GeForce GTX 580M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1211, nv5x_driver_data),
/* GeForce GTX 675M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1212, nv5x_driver_data),
/* GeForce GTX 670M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1213, nv5x_driver_data),
/* GeForce GT 550M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1247, nv5x_driver_data),
/* GeForce GT 555M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1248, nv5x_driver_data),
/* GeForce GT 555M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x124d, nv5x_driver_data),
/* GeForce GTX 560M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1251, nv5x_driver_data),
/* GeForce GT 730M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1290, nv5x_driver_data),
/* GeForce GT 735M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1291, nv5x_driver_data),
/* GeForce GT 740M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1292, nv5x_driver_data),
/* GeForce GT 730M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1293, nv5x_driver_data),
/* GeForce 825M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1293, nv5x_driver_data),
/* GeForce GT 720M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x1298, nv5x_driver_data),

/* NVS 5100M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a2c, nv5x_driver_data),
/* NVS 2100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6a, nv5x_driver_data),
/* NVS 3100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a6c, nv5x_driver_data),
/* NVS 5400M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0def, nv5x_driver_data),
/* NVS 5200M (313.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dfc, nv5x_driver_data),
/* NVS 4200M (180.13)*/
NVIDIABL_DECLARE_GPU_MODEL(0x1056, nv5x_driver_data),
/* NVS 4200M (180.13)*/
NVIDIABL_DECLARE_GPU_MODEL(0x1057, nv5x_driver_data),
/* GeForce GT 620M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1140, nv5x_driver_data),

/* Quadro FX Go 1400 (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x00cc, nv4x_driver_data),
/* Quadro FX 540M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x014c, nv4x_driver_data),
/* Quadro NVS 110M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01da, nv4x_driver_data),
/* Quadro NVS 120M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01db, nv4x_driver_data),
/* Quadro FX 350M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x01dc, nv4x_driver_data),
/* Quadro NVS 510M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x0299, nv4x_driver_data),
/* Quadro FX 2500M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x029a, nv4x_driver_data),
/* Quadro FX 1500M (195.30) */
NVIDIABL_DECLARE_GPU_MODEL(0x029b, nv4x_driver_data),
/* Quadro NVS 300M (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x039a, nv4x_driver_data),
/* QuadroFX 550M (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x039c, nv4x_driver_data),
/* Quadro FX 880M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a3c, nv5x_driver_data),
/* Quadro NVS 370M (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x040a, nv5x_driver_data),
/* Quadro NVS 320M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x040b, nv5x_driver_data),
/* Quadro FX 570M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x040c, nv5x_driver_data),
/* Quadro FX 1600M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x040d, nv5x_driver_data),
/* Quadro NVS 140M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0429, nv5x_driver_data),
/* Quadro NVS 130M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x042a, nv5x_driver_data),
/* Quadro NVS 135M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x042b, nv5x_driver_data),
/* Quadro NVS 135M (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x042c, nv5x_driver_data),
/* Quadro FX 360M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x042d, nv5x_driver_data),
/* Quadro FX 3600M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x061c, nv5x_driver_data),
/* Quadro FX 2800M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x061d, nv5x_driver_data),
/* Quadro FX 3700M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x061e, nv5x_driver_data),
/* Quadro FX 3800M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x061f, nv5x_driver_data),
/* Quadro FX 2700M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x063a, nv5x_driver_data),
/* Quadro FX 380 (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0658, nv5x_driver_data),
/* Quadro FX 580 (NvClock) */
NVIDIABL_DECLARE_GPU_MODEL(0x0659, nv5x_driver_data),
/* Quadro FX 1700M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x065a, nv5x_driver_data),
/* Quadro FX 770M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x065c, nv5x_driver_data),
/* Quadro 5000M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x06da, nv5x_driver_data),
/* Quadro NVS 150M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06ea, nv5x_driver_data),
/* Quadro NVS 160M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06eb, nv5x_driver_data),
/* Quadro FX 370M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x06fb, nv5x_driver_data),
/* Quadro FX 880M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a3c, nv5x_driver_data),
/* Quadro FX 380M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0a7c, nv5x_driver_data),
/* Quadro FX 1800M (195.36) */
NVIDIABL_DECLARE_GPU_MODEL(0x0cbc, nv5x_driver_data),
/* Quadro 1000M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dfa, nv5x_driver_data),
/* Quadro 2000M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dda, nv5x_driver_data),
/* Quadro 500M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0df9, nv5x_driver_data),
/* Quadro 1000M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0dfa, nv5x_driver_data),
/* Quadro 3000M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0e3a, nv5x_driver_data),
/* Quadro 4000M (280.13) */
NVIDIABL_DECLARE_GPU_MODEL(0x0e3b, nv5x_driver_data),
/* Quadro K1100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ff6, nv5x_driver_data),
/* Quadro K500M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ff8, nv5x_driver_data),
/* Quadro K2000M (304.43) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ffb, nv5x_driver_data),
/* Quadro K1000M (304.43) */
NVIDIABL_DECLARE_GPU_MODEL(0x0ffc, nv5x_driver_data),
/* NVS 4200M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1056, nv5x_driver_data),
/* NVS 4200M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x1057, nv5x_driver_data),
/* Quadro 5010M (295.59) */
NVIDIABL_DECLARE_GPU_MODEL(0x109a, nv5x_driver_data),
/* Quadro K3100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11b6, nv5x_driver_data),
/* Quadro K4100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11b7, nv5x_driver_data),
/* Quadro K5100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11b8, nv5x_driver_data),
/* Quadro K5000M (304.43) */
NVIDIABL_DECLARE_GPU_MODEL(0x11bc, nv5x_driver_data),
/* Quadro K4000M (304.43) */
NVIDIABL_DECLARE_GPU_MODEL(0x11bd, nv5x_driver_data),
/* Quadro K3000M (304.43) */
NVIDIABL_DECLARE_GPU_MODEL(0x11be, nv5x_driver_data),
/* Quadro K2100M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x11fc, nv5x_driver_data),
/* Quadro K610M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x12b9, nv5x_driver_data),
/* Quadro K510M (334.21) */
NVIDIABL_DECLARE_GPU_MODEL(0x12ba, nv5x_driver_data),
