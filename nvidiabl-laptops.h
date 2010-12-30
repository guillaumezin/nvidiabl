/*
 * First argument comes from "cat /sys/class/dmi/id/sys_vendor"
 * Second argument comes from "cat /sys/class/dmi/id/product_name" (it can be the beginning of the string only to cover more than one model)
 * Third argument comes from "lspci -nn | grep nVidia", last four hex digits
 *      for instance "01:00.0 VGA compatible controller [0300]: nVidia Corporation G98 [GeForce 9300M GS] [10de:06e9] (rev a1)" gives 0x06e9
 *      obtained number must be listed in "nvidiabl-models.c"
 * Fourth argument is the value to disable the backlight, it is 0 usually, -1 to use default value
 * Fifth is minimum backlight value, -1 to use default value
 * Sixth is maximum backlight value, -1 to use default value
 */

NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-AW11", 0x06e9, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ11", 0x0426, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-FZ38", 0x0426, 0, 50, 1024),
// This has to be BEFORE the general VPCCW1 line
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW17FX", 0x0a74, 0, 1024, 127000),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW1", 0x0a2a, 0, 7000, 2500000),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS117GG", 0x0a75, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS11V9E", 0x0a75, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VGN-S560P", 0x0168, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS12C5E", 0x0168, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCS13V9E", 0x0a75, 0, 50, 110000),
NVIDIABL_DECLARE_LAPTOP_MODEL("Sony Corporation", "VPCCW2", 0x0a75, 0, 50, 110000),
NVIDIABL_DECLARE_LAPTOP_MODEL("Dell Inc.", "Inspiron 1370", 0x0a69, 0, 50, 1024),
NVIDIABL_DECLARE_LAPTOP_MODEL("SAMSUNG ELECTRONICS CO., LTD.", "N510", 0x087f, 0, 50, 1024),

