/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional rwsem compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_RWSEM_H
#define _DRM_KMOD_LINUX_RWSEM_H

#include_next <linux/rwsem.h>

#ifndef down_read_interruptible
static inline int
down_read_interruptible(struct rw_semaphore *sem)
{
	down_read(sem);
	return (0);
}
#endif

#endif /* _DRM_KMOD_LINUX_RWSEM_H */
