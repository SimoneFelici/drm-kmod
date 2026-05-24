/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux string helper compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_STRING_HELPERS_H
#define _DRM_KMOD_LINUX_STRING_HELPERS_H

#include <linux/types.h>
#include <linux/kernel.h>

enum string_size_units {
	STRING_UNITS_10 = 0,
	STRING_UNITS_2 = 1,
};

static inline const char *
str_yes_no(bool v)
{
	return (v ? "yes" : "no");
}

static inline const char *
str_plural(unsigned long n)
{
	return (n == 1 ? "" : "s");
}

static inline void
string_get_size(u64 size, u64 blk_size, const enum string_size_units units,
    char *buf, int len)
{
	u64 bytes;

	bytes = size * blk_size;

	if (units == STRING_UNITS_2) {
		if (bytes >= (1ULL << 30))
			snprintf(buf, len, "%llu GiB", bytes >> 30);
		else if (bytes >= (1ULL << 20))
			snprintf(buf, len, "%llu MiB", bytes >> 20);
		else if (bytes >= (1ULL << 10))
			snprintf(buf, len, "%llu KiB", bytes >> 10);
		else
			snprintf(buf, len, "%llu B", bytes);
	} else {
		if (bytes >= 1000000000ULL)
			snprintf(buf, len, "%llu GB", bytes / 1000000000ULL);
		else if (bytes >= 1000000ULL)
			snprintf(buf, len, "%llu MB", bytes / 1000000ULL);
		else if (bytes >= 1000ULL)
			snprintf(buf, len, "%llu KB", bytes / 1000ULL);
		else
			snprintf(buf, len, "%llu B", bytes);
	}
}

#endif /* _DRM_KMOD_LINUX_STRING_HELPERS_H */
