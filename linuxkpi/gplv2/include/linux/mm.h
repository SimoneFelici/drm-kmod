/*-
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef _DRM_KMOD_LINUX_MM_H
#define _DRM_KMOD_LINUX_MM_H

#include_next <linux/mm.h>

#ifndef VM_MAYSHARE
#define VM_MAYSHARE VM_SHARED
#endif

#ifndef VM_MAYEXEC
#define VM_MAYEXEC VM_EXEC
#endif

#ifndef vm_flags_mod
static inline void
vm_flags_mod(struct vm_area_struct *vma, unsigned long set,
    unsigned long clear)
{
	vma->vm_flags &= ~clear;
	vma->vm_flags |= set;
}
#endif

#endif
