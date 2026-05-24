/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux device/devres compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_DEVICE_H
#define _DRM_KMOD_LINUX_DEVICE_H

#include_next <linux/device.h>

/*
 * FIXME: This is not a complete Linux-compatible devm_release_action().
 *
 * Linux devm_release_action() finds a matching devres action, runs it, and
 * removes it from the device-managed resource list.
 *
 * This temporary compatibility version only invokes the action. A correct
 * implementation should be added to LinuxKPI devres.
 */
static inline void
devm_release_action(struct device *dev, void (*action)(void *), void *data)
{
	action(data);
}

#endif /* _DRM_KMOD_LINUX_DEVICE_H */
