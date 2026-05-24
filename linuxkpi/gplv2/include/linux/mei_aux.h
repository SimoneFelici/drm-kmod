/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux MEI auxiliary device compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_MEI_AUX_H
#define _DRM_KMOD_LINUX_MEI_AUX_H

#include <linux/auxiliary_bus.h>
#include <linux/ioport.h>
#include <linux/types.h>

struct mei_aux_device {
	struct auxiliary_device aux_dev;
	int irq;
	struct resource bar;
	bool slow_firmware;
};

#define auxiliary_dev_to_mei_aux_dev(_auxdev) \
	container_of((_auxdev), struct mei_aux_device, aux_dev)

#endif /* _DRM_KMOD_LINUX_MEI_AUX_H */
