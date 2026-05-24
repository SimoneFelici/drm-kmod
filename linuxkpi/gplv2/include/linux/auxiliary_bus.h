/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux auxiliary bus compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_AUXILIARY_BUS_H
#define _DRM_KMOD_LINUX_AUXILIARY_BUS_H

#include <linux/device.h>
#include <linux/types.h>

struct auxiliary_device {
	struct device dev;
	const char *name;
	u32 id;
};

#define to_auxiliary_dev(_dev) \
	container_of((_dev), struct auxiliary_device, dev)

static inline int
auxiliary_device_init(struct auxiliary_device *auxdev)
{
	return (0);
}

static inline int
auxiliary_device_add(struct auxiliary_device *auxdev)
{
	return (0);
}

static inline void
auxiliary_device_delete(struct auxiliary_device *auxdev)
{
}

static inline void
auxiliary_device_uninit(struct auxiliary_device *auxdev)
{
}

#endif /* _DRM_KMOD_LINUX_AUXILIARY_BUS_H */
