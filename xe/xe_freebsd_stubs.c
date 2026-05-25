/*-
 * SPDX-License-Identifier: MIT
 *
 * Temporary FreeBSD stubs for initial xe.ko bring-up.
 */

#include <sys/sysctl.h>
#include <sys/module.h>

#include <linux/ioport.h>

#ifdef __FreeBSD__
SYSCTL_NODE(_hw, OID_AUTO, xe,
    CTLFLAG_RW | CTLFLAG_MPSAFE, 0,
    "xe parameters");
#endif

/*
 * Linux/i915 provides this for Intel stolen memory.  FreeBSD xe bring-up
 * currently does not populate stolen memory, so leave it empty.
 */
struct resource intel_graphics_stolen_res = { 0 };
#ifdef __FreeBSD__
MODULE_DEPEND(xe, dmabuf, 1, 1, 1);
MODULE_DEPEND(xe, drmn, 2, 2, 2);
MODULE_DEPEND(xe, lindebugfs, 1, 1, 1);
MODULE_DEPEND(xe, ttm, 1, 1, 1);
#endif
