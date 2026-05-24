/*-
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef _DRM_KMOD_LINUX_PERF_EVENT_H
#define _DRM_KMOD_LINUX_PERF_EVENT_H

#include <linux/types.h>

static inline bool
perfmon_capable(void)
{
	return (true);
}

#endif
