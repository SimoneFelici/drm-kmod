/*-
 * SPDX-License-Identifier: MIT
 *
 * Temporary FreeBSD stubs for initial xe.ko bring-up.
 */

#include <linux/ioport.h>

/*
 * Linux/i915 provides this for Intel stolen memory.  FreeBSD xe bring-up
 * currently does not populate stolen memory, so leave it empty.
 */
struct resource intel_graphics_stolen_res = { 0 };
