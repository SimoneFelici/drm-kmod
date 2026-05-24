/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal MMU interval notifier compatibility for drm-kmod.
 *
 * This is enough to make code compile initially. It is not a complete
 * runtime implementation of Linux MMU interval notifiers.
 */

#ifndef _LINUX_MMU_NOTIFIER_H
#define _LINUX_MMU_NOTIFIER_H

#include <linux/types.h>
#include <linux/errno.h>

struct mm_struct;
struct mmu_interval_notifier;

struct mmu_notifier_range {
	struct mm_struct *mm;
	unsigned long start;
	unsigned long end;
	unsigned long flags;
};

struct mmu_interval_notifier_ops {
	bool (*invalidate)(struct mmu_interval_notifier *mni,
	    const struct mmu_notifier_range *range,
	    unsigned long cur_seq);
};

struct mmu_interval_notifier {
	const struct mmu_interval_notifier_ops *ops;
	struct mm_struct *mm;
	unsigned long start;
	unsigned long length;
	unsigned long invalidate_seq;
};

static inline int
mmu_interval_notifier_insert(struct mmu_interval_notifier *mni,
    struct mm_struct *mm, unsigned long start, unsigned long length,
    const struct mmu_interval_notifier_ops *ops)
{
	mni->ops = ops;
	mni->mm = mm;
	mni->start = start;
	mni->length = length;
	mni->invalidate_seq = 0;

	return (0);
}

static inline void
mmu_interval_notifier_remove(struct mmu_interval_notifier *mni)
{
}

static inline unsigned long
mmu_interval_read_begin(struct mmu_interval_notifier *mni)
{
	return (mni->invalidate_seq);
}

static inline bool
mmu_interval_read_retry(struct mmu_interval_notifier *mni, unsigned long seq)
{
	return (false);
}

static inline bool
mmu_interval_check_retry(struct mmu_interval_notifier *mni,
    unsigned long seq)
{
	return mmu_interval_read_retry(mni, seq);
}

static inline bool
mmu_notifier_range_blockable(const struct mmu_notifier_range *range)
{
	return (true);
}

static inline void
mmu_interval_set_seq(struct mmu_interval_notifier *mni, unsigned long seq)
{
	mni->invalidate_seq = seq;
}

#endif /* _LINUX_MMU_NOTIFIER_H */
