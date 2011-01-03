#include "nvidiabl-models.h"

/* Register constants */
#define NV5X_PDISPLAY_OFFSET                            0x00610000
#define NV5X_PDISPLAY_SOR0_BRIGHTNESS                   0x0000c084
#define NV5X_PDIPSLAY_SOR0_BRIGHTNESS_CONTROL_ENABLED   0x80000000

static char *model = "";

static inline unsigned int get_intensity(unsigned int reg_value, int off, int min, int max) {
       
        if (reg_value == off)
                return 0;
        else
                return (reg_value - min) * (FB_BACKLIGHT_LEVELS - 1) / (max - min);
}

static inline unsigned int set_intensity(unsigned int intensity, int off, int min, int max, int forceoff) {
        if (forceoff)
                return off;
        else
                return min + (intensity * (max - min) / (FB_BACKLIGHT_LEVELS - 1));
}

/*
 * Implementation for NV4X chips
 * (NV40, NV41, NV43, NV44, NV46, NV47, NV49, NV4B, C51)
 */
static int nv4x_get_intensity(struct backlight_device *bd)
{
        struct driver_data *dd = bl_get_data(bd);
        unsigned short intensity = ioread16(dd->smartdimmer) & 0x1f;

        intensity = get_intensity(intensity, dd->off, dd->min, dd->max);

        return intensity;
}

static int nv4x_set_intensity(struct backlight_device *bd)
{
        struct driver_data *dd = bl_get_data(bd);
        unsigned intensity;
        
        intensity = set_intensity(
                bd->props.brightness, 
                dd->off, 
                dd->min, 
                dd->max, 
                (bd->props.power != FB_BLANK_UNBLANK || bd->props.fb_blank != FB_BLANK_UNBLANK)
        );
        
        iowrite16((ioread16(dd->smartdimmer) & ~0x1f) | intensity,
                  dd->smartdimmer);
        return 0;
}

static struct driver_data nv4x_driver_data = {
        .bar           = 0,
        .reg_offset    = 0x15f2,
        .reg_size      = 2,
        .off           = 0,
        .min           = 4,
        .max           = 21,
        .backlight_ops = {
#ifdef USE_BACKLIGHT_SUSPEND
                .options        = BL_CORE_SUSPENDRESUME,
#endif
                .get_brightness = nv4x_get_intensity,
                .update_status  = nv4x_set_intensity,
        }
};

/*
 * Implementation for NV5X chips
 * (NV50, G84, G86, G92, G94, G96, GT200)
 */
static int nv5x_get_intensity(struct backlight_device *bd)
{
        struct driver_data *dd = bl_get_data(bd);
        unsigned intensity = ioread32(dd->smartdimmer) &
                ~NV5X_PDIPSLAY_SOR0_BRIGHTNESS_CONTROL_ENABLED;

        intensity = get_intensity(intensity, dd->off, dd->min, dd->max);

        return intensity;
}

static int nv5x_set_intensity(struct backlight_device *bd)
{
        struct driver_data *dd = bl_get_data(bd);
        unsigned intensity;
        
        intensity = set_intensity(
                bd->props.brightness, 
                dd->off, 
                dd->min, 
                dd->max, 
                (bd->props.power != FB_BLANK_UNBLANK || bd->props.fb_blank != FB_BLANK_UNBLANK)
        );
        
        iowrite32(intensity | NV5X_PDIPSLAY_SOR0_BRIGHTNESS_CONTROL_ENABLED,
                  dd->smartdimmer);
        return 0;
}

static struct driver_data nv5x_driver_data = {
        .bar           = 0,
        .reg_offset    = NV5X_PDISPLAY_OFFSET + NV5X_PDISPLAY_SOR0_BRIGHTNESS,
        .reg_size      = 4,
        .off           = 0,
        .min           = 50,
        .max           = 1024,
        .backlight_ops = {
#ifdef USE_BACKLIGHT_SUSPEND
                .options        = BL_CORE_SUSPENDRESUME,
#endif
                .get_brightness = nv5x_get_intensity,
                .update_status  = nv5x_set_intensity,
        }
};

void nvidiabl_force_model(struct driver_data **driver_data) {
        /* Look for a forced algorithm */
        if (strncasecmp(model, "NV5X", 4) == 0) {
                *driver_data = &nv5x_driver_data;                
                printk(KERN_INFO "nvidiabl: forced to nv5x algorithm\n");
        }
        else if (strncasecmp(model, "NV4X", 4) == 0) {
                *driver_data = &nv4x_driver_data;
                printk(KERN_INFO "nvidiabl: forced to nv4x algorithm\n");
        }
}

/*
 * Device matching.
 * The list of supported devices was primarily taken from NvClock,
 * but only contains the mobile chips.
 */
DEFINE_PCI_DEVICE_TABLE(nvidiabl_device_table) = {
        /* nVidia Geforce Go 7800GTX */
        { PCI_VDEVICE(NVIDIA, 0x0099), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6800 */
        { PCI_VDEVICE(NVIDIA, 0x00c8), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6800Ultra */
        { PCI_VDEVICE(NVIDIA, 0x00c9), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia QuadroFX Go 1400 */
        { PCI_VDEVICE(NVIDIA, 0x00cc), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6600 */
        { PCI_VDEVICE(NVIDIA, 0x0144), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia GeForce Go 6600TE/6200TE */
        { PCI_VDEVICE(NVIDIA, 0x0146), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6600 */
        { PCI_VDEVICE(NVIDIA, 0x0148), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6600GT */
        { PCI_VDEVICE(NVIDIA, 0x0149), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6200 */
        { PCI_VDEVICE(NVIDIA, 0x0164), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6400 */
        { PCI_VDEVICE(NVIDIA, 0x0166), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6200 */
        { PCI_VDEVICE(NVIDIA, 0x0167), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 6400 */
        { PCI_VDEVICE(NVIDIA, 0x0168), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7300 */
        { PCI_VDEVICE(NVIDIA, 0x01d7), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7400 */
        { PCI_VDEVICE(NVIDIA, 0x01d8), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7400GS */
        { PCI_VDEVICE(NVIDIA, 0x01d9), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Quadro NVS 110M */
        { PCI_VDEVICE(NVIDIA, 0x01da), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Quadro NVS 120M */
        { PCI_VDEVICE(NVIDIA, 0x01db), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia QuadroFX 350M */
        { PCI_VDEVICE(NVIDIA, 0x01dc), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce 7500LE */
        { PCI_VDEVICE(NVIDIA, 0x01dd), (kernel_ulong_t)&nv4x_driver_data },
        /* NV44M */
        { PCI_VDEVICE(NVIDIA, 0x0228), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7950GTX */
        { PCI_VDEVICE(NVIDIA, 0x0297), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7900GS */
        { PCI_VDEVICE(NVIDIA, 0x0298), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7900GTX */
        { PCI_VDEVICE(NVIDIA, 0x0299), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia QuadroFX 2500M */
        { PCI_VDEVICE(NVIDIA, 0x029a), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia QuadroFX 1500M */
        { PCI_VDEVICE(NVIDIA, 0x029b), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7700 */
        { PCI_VDEVICE(NVIDIA, 0x0397), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7600 */
        { PCI_VDEVICE(NVIDIA, 0x0398), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7600GT */
        { PCI_VDEVICE(NVIDIA, 0x0399), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Quadro NVS 300M */
        { PCI_VDEVICE(NVIDIA, 0x039a), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce Go 7900SE */
        { PCI_VDEVICE(NVIDIA, 0x039b), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia QuadroFX 550M */
        { PCI_VDEVICE(NVIDIA, 0x039c), (kernel_ulong_t)&nv4x_driver_data },
        /* nVidia Geforce 9500M GS */
        { PCI_VDEVICE(NVIDIA, 0x0405), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce NB9P-GE */
        { PCI_VDEVICE(NVIDIA, 0x0406), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8600M GT */
        { PCI_VDEVICE(NVIDIA, 0x0407), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8600M GTS */
        { PCI_VDEVICE(NVIDIA, 0x0408), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8700M GT */
        { PCI_VDEVICE(NVIDIA, 0x0409), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 370M */
        { PCI_VDEVICE(NVIDIA, 0x040a), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 320M */
        { PCI_VDEVICE(NVIDIA, 0x040b), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia QuadroFX 570M */
        { PCI_VDEVICE(NVIDIA, 0x040c), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia QuadroFX 1600M */
        { PCI_VDEVICE(NVIDIA, 0x040d), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8600M GS */
        { PCI_VDEVICE(NVIDIA, 0x0425), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8400M GT */
        { PCI_VDEVICE(NVIDIA, 0x0426), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8400M GS */
        { PCI_VDEVICE(NVIDIA, 0x0427), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8400M G */
        { PCI_VDEVICE(NVIDIA, 0x0428), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 140M */
        { PCI_VDEVICE(NVIDIA, 0x0429), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 130M */
        { PCI_VDEVICE(NVIDIA, 0x042a), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 135M */
        { PCI_VDEVICE(NVIDIA, 0x042b), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro FX 360M */
        { PCI_VDEVICE(NVIDIA, 0x042d), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9300M G */
        { PCI_VDEVICE(NVIDIA, 0x042e), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8800M GTS */
        { PCI_VDEVICE(NVIDIA, 0x0609), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 8800M GTX */
        { PCI_VDEVICE(NVIDIA, 0x060c), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia QuadroFX 3600M */
        { PCI_VDEVICE(NVIDIA, 0x061c), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9600M GT */
        { PCI_VDEVICE(NVIDIA, 0x0647), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9600M GS */
        { PCI_VDEVICE(NVIDIA, 0x0648), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9600M GT */
        { PCI_VDEVICE(NVIDIA, 0x0649), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9500M G */
        { PCI_VDEVICE(NVIDIA, 0x064b), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9300M GS */
        { PCI_VDEVICE(NVIDIA, 0x06e5), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9200M GS */
        { PCI_VDEVICE(NVIDIA, 0x06e8), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9300M GS */
        { PCI_VDEVICE(NVIDIA, 0x06e9), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 150M */
        { PCI_VDEVICE(NVIDIA, 0x06ea), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Quadro NVS 160M */
        { PCI_VDEVICE(NVIDIA, 0x06eb), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce G105M */
        { PCI_VDEVICE(NVIDIA, 0x06ec), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia QuadroFX 370M */
        { PCI_VDEVICE(NVIDIA, 0x06fb), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 9400M */
        { PCI_VDEVICE(NVIDIA, 0x0863), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce 9400M */
        { PCI_VDEVICE(NVIDIA, 0x0870), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce 9200 */
        { PCI_VDEVICE(NVIDIA, 0x0871), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce G102M */
        { PCI_VDEVICE(NVIDIA, 0x0872), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce G102M */
        { PCI_VDEVICE(NVIDIA, 0x0873), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA Quadro FX 470 */
        { PCI_VDEVICE(NVIDIA, 0x087a), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA Quadro FX 470 */
        { PCI_VDEVICE(NVIDIA, 0x087f), (kernel_ulong_t)&nv5x_driver_data },
	/* NVIDIA GeForce 210M */
	{ PCI_VDEVICE(NVIDIA, 0x0a74), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce 230M */
        { PCI_VDEVICE(NVIDIA, 0x0a2a), (kernel_ulong_t)&nv5x_driver_data },
        /* nVidia Geforce 305M */
        { PCI_VDEVICE(NVIDIA, 0x0a69), (kernel_ulong_t)&nv5x_driver_data },
        /* NVIDIA GeForce 310M */
        { PCI_VDEVICE(NVIDIA, 0x0a75), (kernel_ulong_t)&nv5x_driver_data },
	/* NVIDIA GeForce 330M */
	{ PCI_VDEVICE(NVIDIA, 0x0a2b), (kernel_ulong_t)&nv5x_driver_data },
        /* end of list */
        { }
};

module_param_named(model, model, charp, 0644);
MODULE_PARM_DESC(model, "backlight model, must be empty for autodetection, nv4x or nv5x");
