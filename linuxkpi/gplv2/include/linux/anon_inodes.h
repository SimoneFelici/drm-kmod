/*-
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef _DRM_KMOD_LINUX_ANON_INODES_H
#define _DRM_KMOD_LINUX_ANON_INODES_H

#include_next <linux/anon_inodes.h>
#include <linux/errno.h>

#ifndef anon_inode_getfd
static inline int
anon_inode_getfd(const char *name, const struct file_operations *fops,
    void *priv, int flags)
{
	return (-ENOSYS);
}
#endif

#endif
