/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional iosys-map compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_IOSYS_MAP_H
#define _DRM_KMOD_LINUX_IOSYS_MAP_H

#include_next <linux/iosys-map.h>

static inline void
iosys_map_memcpy_from(void *dst, const struct iosys_map *src,
    size_t src_offset, size_t len)
{
	if (src->is_iomem)
		memcpy_fromio(dst, src->vaddr_iomem + src_offset, len);
	else
		memcpy(dst, src->vaddr + src_offset, len);
}

#endif /* _DRM_KMOD_LINUX_IOSYS_MAP_H */
