#include <linux/module.h>
#include <linux/printk.h>

/*
extern bool camera_legacy_enable;

	if (!camera_legacy_enable)
		return -ENODEV;
*/

bool camera_legacy_enable = false;

static int __init camera_legacy_init(void)
{
#if IS_ENABLED(CONFIG_MACH_XIAOMI_VINCE) || \
    IS_ENABLED(CONFIG_MACH_XIAOMI_DAISY) || \
    IS_ENABLED(CONFIG_MACH_XIAOMI_SAKURA) || \
    IS_ENABLED(CONFIG_MACH_XIAOMI_TISSOT) || \
    IS_ENABLED(CONFIG_MACH_XIAOMI_ROSY) || \
    IS_ENABLED(CONFIG_MACH_XIAOMI_YSL)
	camera_legacy_enable = true;
#endif

#if IS_ENABLED(CONFIG_MSMB_CAMERA_LEGACY_M) || \
    IS_ENABLED(CONFIG_MSMB_CAMERA_LEGACY_N)
#if IS_ENABLED(CONFIG_MACH_XIAOMI_MIDO) || IS_ENABLED(CONFIG_MACH_XIAOMI_MARKW)
	camera_legacy_enable = false;
#endif
#endif

	if (camera_legacy_enable)
		pr_info("Enable Legacy Camera Stack.\n");

	return 0;
}

module_init(camera_legacy_init);
