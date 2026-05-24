/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux KUnit compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_KUNIT_H
#define _DRM_KMOD_LINUX_KUNIT_H

#ifndef EXPORT_SYMBOL_IF_KUNIT
#define EXPORT_SYMBOL_IF_KUNIT(sym)
#endif

struct kunit;

static inline struct kunit *
kunit_get_current_test(void)
{
	return (NULL);
}

#endif /* _DRM_KMOD_LINUX_KUNIT_H */
