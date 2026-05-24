/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Additional Linux bitmap compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_BITMAP_H
#define _DRM_KMOD_LINUX_BITMAP_H

#include_next <linux/bitmap.h>

#ifndef BITS_PER_LONG
#define BITS_PER_LONG (sizeof(unsigned long) * 8)
#endif

static inline void
bitmap_shift_left(unsigned long *dst, const unsigned long *src,
    unsigned int shift, unsigned int nbits)
{
	unsigned int i;

	bitmap_zero(dst, nbits);

	if (shift >= nbits)
		return;

	for (i = 0; i + shift < nbits; i++) {
		if (test_bit(i, src))
			set_bit(i + shift, dst);
	}
}

static inline void
bitmap_set_value8(unsigned long *map, unsigned long value,
    unsigned long start)
{
	unsigned int i;

	for (i = 0; i < 8; i++) {
		if (value & BIT(i))
			set_bit(start + i, map);
		else
			clear_bit(start + i, map);
	}
}

static inline bool
bitmap_or_bit(const unsigned long *addr1, const unsigned long *addr2,
    unsigned long nr)
{
	return (test_bit(nr, addr1) || test_bit(nr, addr2));
}

#ifndef for_each_or_bit
#define for_each_or_bit(_bit, _addr1, _addr2, _size)			\
	for ((_bit) = 0; (_bit) < (_size); (_bit)++)			\
		if (!bitmap_or_bit((_addr1), (_addr2), (_bit))) {	\
		} else
#endif

static inline unsigned long
bitmap_next_bitrange_start(const unsigned long *bitmap, unsigned long start,
    unsigned long nbits, bool set)
{
	unsigned long bit;

	for (bit = start; bit < nbits; bit++) {
		if (!!test_bit(bit, bitmap) == set)
			return (bit);
	}

	return (nbits);
}

static inline unsigned long
bitmap_next_bitrange_end(const unsigned long *bitmap, unsigned long start,
    unsigned long nbits, bool set)
{
	unsigned long bit;

	for (bit = start; bit < nbits; bit++) {
		if (!!test_bit(bit, bitmap) != set)
			return (bit);
	}

	return (nbits);
}

#ifndef for_each_set_bitrange
#define for_each_set_bitrange(_rs, _re, _bitmap, _nbits)		\
	for ((_rs) = bitmap_next_bitrange_start((_bitmap), 0, (_nbits), true), \
	    (_re) = bitmap_next_bitrange_end((_bitmap), (_rs), (_nbits), true); \
	    (_rs) < (_nbits);						\
	    (_rs) = bitmap_next_bitrange_start((_bitmap), (_re), (_nbits), true), \
	    (_re) = bitmap_next_bitrange_end((_bitmap), (_rs), (_nbits), true))
#endif

#ifndef for_each_clear_bitrange
#define for_each_clear_bitrange(_rs, _re, _bitmap, _nbits)		\
	for ((_rs) = bitmap_next_bitrange_start((_bitmap), 0, (_nbits), false), \
	    (_re) = bitmap_next_bitrange_end((_bitmap), (_rs), (_nbits), false); \
	    (_rs) < (_nbits);						\
	    (_rs) = bitmap_next_bitrange_start((_bitmap), (_re), (_nbits), false), \
	    (_re) = bitmap_next_bitrange_end((_bitmap), (_rs), (_nbits), false))
#endif

#endif /* _DRM_KMOD_LINUX_BITMAP_H */
