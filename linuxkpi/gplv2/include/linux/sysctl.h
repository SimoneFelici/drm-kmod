/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux sysctl compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_SYSCTL_H
#define _DRM_KMOD_LINUX_SYSCTL_H

#include <linux/types.h>

struct ctl_table;
struct ctl_table_header;

typedef int (*proc_handler_t)(struct ctl_table *table, int write,
    void *buffer, size_t *lenp, loff_t *ppos);

struct ctl_table {
	const char *procname;
	void *data;
	int maxlen;
	umode_t mode;
	proc_handler_t proc_handler;
	void *extra1;
	void *extra2;
	struct ctl_table *child;
};

static int sysctl_zero;
static int sysctl_one = 1;

#define SYSCTL_ZERO	(&sysctl_zero)
#define SYSCTL_ONE	(&sysctl_one)

static inline int
proc_dointvec_minmax(struct ctl_table *table, int write,
    void *buffer, size_t *lenp, loff_t *ppos)
{
	return (0);
}

static inline struct ctl_table_header *
register_sysctl(const char *path, struct ctl_table *table)
{
	return (NULL);
}

static inline void
unregister_sysctl_table(struct ctl_table_header *header)
{
}

#endif /* _DRM_KMOD_LINUX_SYSCTL_H */
