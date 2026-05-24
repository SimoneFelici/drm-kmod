/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux errno compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_ERRNO_H
#define _DRM_KMOD_LINUX_ERRNO_H

#include_next <linux/errno.h>

#ifndef EREMCHG
#define EREMCHG		78
#endif

#ifndef ENOPKG
#define ENOPKG		65
#endif

#endif /* _DRM_KMOD_LINUX_ERRNO_H */
