/*-
 * SPDX-License-Identifier: GPL-2.0
 */

#ifndef _DRM_KMOD_LINUX_UUID_H
#define _DRM_KMOD_LINUX_UUID_H

#include_next <linux/uuid.h>

#ifndef UUID_STRING_LEN
#define UUID_STRING_LEN 36
#endif

#ifndef uuid_is_valid
static inline bool
uuid_is_valid(const char *uuid)
{
	const char *p;
	int i;

	if (uuid == NULL)
		return (false);

	for (i = 0, p = uuid; i < UUID_STRING_LEN; i++, p++) {
		if (i == 8 || i == 13 || i == 18 || i == 23) {
			if (*p != '-')
				return (false);
		} else if (!((*p >= '0' && *p <= '9') ||
		    (*p >= 'a' && *p <= 'f') ||
		    (*p >= 'A' && *p <= 'F'))) {
			return (false);
		}
	}

	return (uuid[UUID_STRING_LEN] == '\0');
}
#endif

#endif
