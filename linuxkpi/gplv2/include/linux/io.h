/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux IO compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_IO_H
#define _DRM_KMOD_LINUX_IO_H

#include_next <linux/io.h>

#ifndef devm_ioremap_wc
static inline void *
devm_ioremap_wc(struct device *dev, resource_size_t offset, resource_size_t size)
{
	return devm_ioremap(dev, offset, size);
}
#endif

#endif /* _DRM_KMOD_LINUX_IO_H */
