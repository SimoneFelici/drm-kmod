/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal Linux IRQ compatibility for drm-kmod.
 */

#ifndef _DRM_KMOD_LINUX_IRQ_H
#define _DRM_KMOD_LINUX_IRQ_H

#include <linux/types.h>

struct irq_desc;

struct irq_data {
	void *chip_data;
};

struct irq_chip {
	const char *name;
	void (*irq_mask)(struct irq_data *data);
	void (*irq_unmask)(struct irq_data *data);
};

typedef void (*irq_flow_handler_t)(struct irq_desc *desc);

static inline void
handle_simple_irq(struct irq_desc *desc)
{
}

static inline int
irq_alloc_desc(int node)
{
	return (0);
}

static inline void
irq_free_desc(unsigned int irq)
{
}

static inline void
irq_set_chip_and_handler_name(unsigned int irq,
    const struct irq_chip *chip, irq_flow_handler_t handler,
    const char *name)
{
}

static inline int
irq_set_chip_data(unsigned int irq, void *data)
{
	return (0);
}

static inline int
generic_handle_irq(unsigned int irq)
{
	return (0);
}

#endif /* _DRM_KMOD_LINUX_IRQ_H */
