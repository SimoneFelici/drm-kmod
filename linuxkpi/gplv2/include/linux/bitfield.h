/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux bitfield compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_BITFIELD_H
#define _DRM_KMOD_LINUX_BITFIELD_H

#include_next <linux/bitfield.h>

#ifndef FIELD_MAX
#define FIELD_MAX(_mask) \
	((_mask) >> __builtin_ctzl(_mask))
#endif

#endif /* _DRM_KMOD_LINUX_BITFIELD_H */
