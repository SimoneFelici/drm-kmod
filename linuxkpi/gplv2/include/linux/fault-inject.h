/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux fault injection compatibility for drm-kmod.
 *
 * This is not a full fault-injection framework. It is only enough to
 * satisfy drivers that call should_fail() for optional debug/fault paths.
 */

#ifndef _LINUX_FAULT_INJECT_H
#define _LINUX_FAULT_INJECT_H

#include <linux/types.h>

struct fault_attr {
	int dummy;
};

static inline bool
should_fail(struct fault_attr *attr, ssize_t size)
{
	return (false);
}

#endif /* _LINUX_FAULT_INJECT_H */
