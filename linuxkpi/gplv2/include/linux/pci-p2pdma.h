/*-
 * SPDX-License-Identifier: GPL-2.0
 *
 * Minimal PCI P2PDMA/MSI/PM/ReBAR compatibility for drm-kmod.
 */

#ifndef _LINUX_PCI_P2PDMA_H
#define _LINUX_PCI_P2PDMA_H

#include <linux/pci.h>
#include <sys/bus.h>

#ifndef IORESOURCE_MEM_64
#define IORESOURCE_MEM_64	0
#endif

#ifndef IORESOURCE_UNSET
#define IORESOURCE_UNSET	0
#endif

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
	return (pdev->msi_enabled || pdev->msix_enabled);
}
#endif

#ifndef pci_msix_vec_count
static inline int
pci_msix_vec_count(struct pci_dev *pdev)
{
	return (pci_msix_count(pdev->dev.bsddev));
}
#endif

#ifndef pci_d3cold_disable
static inline void
pci_d3cold_disable(struct pci_dev *pdev)
{
}
#endif

#ifndef pci_d3cold_enable
static inline void
pci_d3cold_enable(struct pci_dev *pdev)
{
}
#endif

#ifndef pci_pr3_present
static inline bool
pci_pr3_present(struct pci_dev *pdev)
{
	return (false);
}
#endif

#ifndef pci_rebar_bytes_to_size
static inline int
pci_rebar_bytes_to_size(u64 bytes)
{
	int size = 0;

	if (!bytes)
		return (-1);

	while (bytes > 1) {
		bytes >>= 1;
		size++;
	}

	return (size);
}
#endif

#ifndef pci_rebar_get_possible_sizes
static inline u32
pci_rebar_get_possible_sizes(struct pci_dev *pdev, int bar)
{
	return (0);
}
#endif

#ifndef pci_resize_resource
static inline int
pci_resize_resource(struct pci_dev *pdev, int bar, int size)
{
	return (-ENODEV);
}
#endif

#ifndef pci_assign_unassigned_bus_resources
static inline void
pci_assign_unassigned_bus_resources(struct pci_bus *bus)
{
}
#endif


#ifndef pci_sriov_get_totalvfs
static inline int
pci_sriov_get_totalvfs(struct pci_dev *pdev)
{
	return (0);
}
#endif


#ifndef pci_sriov_set_totalvfs
static inline int
pci_sriov_set_totalvfs(struct pci_dev *pdev, u16 numvfs)
{
	return (0);
}
#endif

#endif /* _LINUX_PCI_P2PDMA_H */
