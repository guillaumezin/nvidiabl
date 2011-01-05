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

#include "nvidiabl-gpu.h"
  
        /* end of list */
        { }
};

module_param_named(model, model, charp, 0644);
MODULE_PARM_DESC(model, "backlight model, must be empty for autodetection, nv4x or nv5x");
