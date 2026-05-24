/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux fault-injection compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_FAULT_INJECT_H
#define _DRM_KMOD_LINUX_FAULT_INJECT_H

#include <linux/types.h>

struct dentry;

struct fault_attr {
	unsigned long probability;
	unsigned long interval;
	unsigned long times;
	unsigned long space;
	bool verbose;
};

#ifndef DECLARE_FAULT_ATTR
#define DECLARE_FAULT_ATTR(name) \
	struct fault_attr name = { 0 }
#endif

static inline bool
should_fail(struct fault_attr *attr, int size)
{
	return (false);
}

static inline void
fault_create_debugfs_attr(const char *name, struct dentry *parent,
    struct fault_attr *attr)
{
}

#endif /* _DRM_KMOD_LINUX_FAULT_INJECT_H */
