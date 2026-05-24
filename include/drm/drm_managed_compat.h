/*-
 * SPDX-License-Identifier: MIT
 *
 * Additional DRM managed compatibility helpers for drm-kmod.
 */

#ifndef _DRM_MANAGED_COMPAT_H_
#define _DRM_MANAGED_COMPAT_H_

#include <drm/drm_managed.h>
#include <linux/mutex.h>
#include <linux/slab.h>

#ifndef drmm_kmalloc
static inline void *
drmm_kmalloc(struct drm_device *dev, size_t size, gfp_t gfp)
{
	return drmm_kzalloc(dev, size, gfp);
}
#endif

#ifndef drmm_mutex_init
static inline int
drmm_mutex_init(struct drm_device *dev, struct mutex *lock)
{
	mutex_init(lock);
	return (0);
}
#endif

#endif /* _DRM_MANAGED_COMPAT_H_ */
