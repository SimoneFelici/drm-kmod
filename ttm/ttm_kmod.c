/*-
 * SPDX-License-Identifier: MIT
 */

#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>

static int
ttm_modevent(module_t mod, int type, void *data)
{
	return (0);
}

static moduledata_t ttm_mod = {
	"ttm",
	ttm_modevent,
	NULL
};

DECLARE_MODULE(ttm, ttm_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
MODULE_VERSION(ttm, 1);
