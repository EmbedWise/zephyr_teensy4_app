/**
 * @file main.c
 * @author Bob Peters
 * @brief Application startup
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022 EmbedWise
 * 
 */

#include <zephyr.h>
#include <logging/log.h>

#include <usb/usb_device.h>


#define START_DELAY 2000


LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);


void main(void)
{
	uint32_t version = sys_kernel_version_get();

	if (usb_enable(NULL)) {
		return;
	}

	k_msleep(START_DELAY);

	LOG_INF("Started zephyr %u.%u.%u on board %s/%s.", SYS_KERNEL_VER_MAJOR(version), SYS_KERNEL_VER_MINOR(version), SYS_KERNEL_VER_PATCHLEVEL(version), CONFIG_ARCH, CONFIG_BOARD);
}