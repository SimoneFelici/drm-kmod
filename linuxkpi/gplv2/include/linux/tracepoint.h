/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux tracepoint compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_TRACEPOINT_H
#define _DRM_KMOD_LINUX_TRACEPOINT_H

#include_next <linux/tracepoint.h>

/*
 * Linux has DEFINE_EVENT_PRINT(template, name, proto, args, print).
 *
 * Do not implement this by expanding to DEFINE_EVENT(), because TP_PROTO(...)
 * may contain commas and gets macro-expanded too early through the wrapper.
 *
 * FreeBSD LinuxKPI tracepoints are no-op stubs here, so emit the same kind of
 * static inline trace function directly and ignore args/print.
 */
#ifndef DEFINE_EVENT_PRINT
#define DEFINE_EVENT_PRINT(_template, _name, _proto, _args, _print)	\
static inline void trace_ ## _name(_proto)				\
{									\
}
#endif

#endif /* _DRM_KMOD_LINUX_TRACEPOINT_H */
