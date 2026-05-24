/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux PM compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_PM_H
#define _DRM_KMOD_LINUX_PM_H

#include_next <linux/pm.h>

#ifndef SET_RUNTIME_PM_OPS
#define SET_RUNTIME_PM_OPS(_suspend, _resume, _idle)	\
	.runtime_suspend = (_suspend),			\
	.runtime_resume = (_resume),			\
	.runtime_idle = (_idle),
#endif

#ifndef RPM_SUSPENDING
#define RPM_SUSPENDING 1
#endif

#ifndef RPM_RESUMING
#define RPM_RESUMING 2
#endif

#ifndef pm_runtime_resume_and_get
static inline int
pm_runtime_resume_and_get(struct device *dev)
{
	return (0);
}
#endif

#ifndef device_set_pm_not_required
static inline void
device_set_pm_not_required(struct device *dev)
{
}
#endif

#endif /* _DRM_KMOD_LINUX_PM_H */
