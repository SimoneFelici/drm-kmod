/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux kthread compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_KTHREAD_H
#define _DRM_KMOD_LINUX_KTHREAD_H

#include_next <linux/kthread.h>

struct mm_struct;

#ifndef kthread_use_mm
static inline void
kthread_use_mm(struct mm_struct *mm)
{
}
#endif

#ifndef kthread_unuse_mm
static inline void
kthread_unuse_mm(struct mm_struct *mm)
{
}
#endif

#endif /* _DRM_KMOD_LINUX_KTHREAD_H */
