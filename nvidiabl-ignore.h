/*
 * First argument comes from "cat /sys/class/dmi/id/sys_vendor"
 * Second argument comes from "cat /sys/class/dmi/id/product_name"
 * Third argument comes from "lspci -nn | grep nVidia", last four hex digits
 *      for instance "01:00.0 VGA compatible controller [0300]: nVidia Corporation G98 [GeForce 9300M GS] [10de:06e9] (rev a1)" gives 0x06e9
 */

NVIDIABL_IGNORE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,1", 0x0863),
NVIDIABL_IGNORE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,2", 0x0863),
NVIDIABL_IGNORE_LAPTOP_MODEL("Apple Inc.", "MacBookPro5,5", 0x0863),
