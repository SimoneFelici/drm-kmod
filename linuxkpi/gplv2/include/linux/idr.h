/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux IDR compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_IDR_H
#define _DRM_KMOD_LINUX_IDR_H

#include_next <linux/idr.h>

#ifndef idr_init_base
static inline void
idr_init_base(struct idr *idr, int base)
{
	idr_init(idr);
}
#endif

#endif /* _DRM_KMOD_LINUX_IDR_H */
