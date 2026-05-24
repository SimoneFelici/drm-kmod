/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux component framework compatibility for drm-kmod.
 *
 * This is currently a no-op implementation. It is enough for drivers that
 * register optional components, but it is not a full component framework.
 */

#ifndef _DRM_KMOD_LINUX_COMPONENT_H
#define _DRM_KMOD_LINUX_COMPONENT_H

#include <linux/device.h>
#include <linux/types.h>

struct component_ops {
	int (*bind)(struct device *comp, struct device *master,
	    void *master_data);
	void (*unbind)(struct device *comp, struct device *master,
	    void *master_data);
};

#ifndef COMPONENT_TYPE_GSC_PROXY
#define COMPONENT_TYPE_GSC_PROXY 0
#endif

static inline int
component_add(struct device *dev, const struct component_ops *ops)
{
	return (0);
}

static inline int
component_add_typed(struct device *dev, const struct component_ops *ops,
    int type)
{
	return component_add(dev, ops);
}

static inline void
component_del(struct device *dev, const struct component_ops *ops)
{
}

#endif /* _DRM_KMOD_LINUX_COMPONENT_H */
