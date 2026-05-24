/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux sizes compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_SIZES_H
#define _DRM_KMOD_LINUX_SIZES_H

#include_next <linux/sizes.h>

/*
 * FreeBSD LinuxKPI may define SZ_2G as a signed int expression:
 *   1024 * 1024 * 1024 * 2
 * which overflows before promotion.
 */
#ifdef SZ_2G
#undef SZ_2G
#endif
#define SZ_2G		(2ULL * 1024ULL * 1024ULL * 1024ULL)

#endif /* _DRM_KMOD_LINUX_SIZES_H */
