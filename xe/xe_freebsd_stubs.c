/*-
 * SPDX-License-Identifier: MIT
 *
 * Temporary FreeBSD stubs for initial xe.ko bring-up.
 */

#include <sys/sysctl.h>

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
