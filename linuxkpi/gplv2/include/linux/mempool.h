/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux mempool compatibility helpers for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_MEMPOOL_H
#define _DRM_KMOD_LINUX_MEMPOOL_H

#include <linux/slab.h>
#include <linux/types.h>
#include <linux/gfp.h>

typedef void *(*mempool_alloc_t)(gfp_t gfp_mask, void *pool_data);
typedef void (*mempool_free_t)(void *element, void *pool_data);

typedef struct mempool_s {
	mempool_alloc_t alloc;
	mempool_free_t free;
	void *pool_data;
	bool initialized;
} mempool_t;

static inline void *
mempool_kmalloc(gfp_t gfp_mask, void *pool_data)
{
	size_t size = (size_t)pool_data;

	return kmalloc(size, gfp_mask);
}

static inline void
mempool_kfree(void *element, void *pool_data)
{
	kfree(element);
}

static inline bool
mempool_initialized(mempool_t *pool)
{
	return (pool != NULL && pool->initialized);
}

static inline int
mempool_init(mempool_t *pool, int min_nr, mempool_alloc_t alloc_fn,
    mempool_free_t free_fn, void *pool_data)
{
	pool->alloc = alloc_fn;
	pool->free = free_fn;
	pool->pool_data = pool_data;
	pool->initialized = true;

	return (0);
}

static inline int
mempool_init_kmalloc_pool(mempool_t *pool, int min_nr, size_t size)
{
	return mempool_init(pool, min_nr, mempool_kmalloc, mempool_kfree,
	    (void *)size);
}

static inline void
mempool_exit(mempool_t *pool)
{
	if (pool)
		pool->initialized = false;
}

static inline void *
mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
{
	if (!pool || !pool->initialized || !pool->alloc)
		return (NULL);

	return pool->alloc(gfp_mask, pool->pool_data);
}

static inline void
mempool_free(void *element, mempool_t *pool)
{
	if (!element)
		return;

	if (pool && pool->free)
		pool->free(element, pool->pool_data);
	else
		kfree(element);
}

#endif /* _DRM_KMOD_LINUX_MEMPOOL_H */
