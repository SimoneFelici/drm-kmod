/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux lockdep compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_LOCKDEP_H
#define _DRM_KMOD_LINUX_LOCKDEP_H

#include_next <linux/lockdep.h>

#ifndef lockdep_assert_held_write
#define lockdep_assert_held_write(l) do { } while (0)
#endif

#ifndef lockdep_assert_held_read
#define lockdep_assert_held_read(l) do { } while (0)
#endif

#endif /* _DRM_KMOD_LINUX_LOCKDEP_H */
