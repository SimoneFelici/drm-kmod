/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal PCI P2PDMA/MSI compatibility for drm-kmod.
 */

#ifndef _LINUX_PCI_P2PDMA_H
#define _LINUX_PCI_P2PDMA_H

#include <linux/pci.h>

static inline int
pci_p2pdma_distance(struct pci_dev *provider, struct device *client,
    bool verbose)
{
	return (-1);
}

#ifndef pci_dev_msi_enabled
static inline bool
pci_dev_msi_enabled(struct pci_dev *pdev)
{
	/*
	 * Conservative placeholder. A correct implementation should query the
	 * FreeBSD PCI MSI/MSI-X state for this device.
	 */
	return (true);
}
#endif

#endif /* _LINUX_PCI_P2PDMA_H */
