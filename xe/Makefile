.include "../kconfig.mk"

SRCDIR=	${.CURDIR:H}/drivers/gpu/drm/xe
GENDIR=	${.CURDIR}/generated
WA_GEN=	${.CURDIR}/xe_gen_wa_oob
WA_RULES= ${SRCDIR}/xe_wa_oob.rules
WA_C=	${GENDIR}/xe_wa_oob.c
WA_H=	${GENDIR}/xe_wa_oob.h

.PATH:	${SRCDIR} \
	${SRCDIR}/regs \
	${SRCDIR}/instructions \
	${GENDIR}

KMOD=	xe

EXPORT_SYMS=	YES

SRCS=	\
	xe_bb.c \
	xe_bo.c \
	xe_bo_evict.c \
	xe_devcoredump.c \
	xe_device.c \
	xe_device_sysfs.c \
	xe_dma_buf.c \
	xe_drm_client.c \
	xe_exec.c \
	xe_execlist.c \
	xe_exec_queue.c \
	xe_force_wake.c \
	xe_ggtt.c \
	xe_gpu_scheduler.c \
	xe_gsc.c \
	xe_gsc_debugfs.c \
	xe_gsc_proxy.c \
	xe_gsc_submit.c \
	xe_gt.c \
	xe_gt_ccs_mode.c \
	xe_gt_clock.c \
	xe_gt_freq.c \
	xe_gt_idle.c \
	xe_gt_mcr.c \
	xe_gt_pagefault.c \
	xe_gt_sysfs.c \
	xe_gt_throttle.c \
	xe_gt_tlb_invalidation.c \
	xe_gt_topology.c \
	xe_guc.c \
	xe_guc_ads.c \
	xe_guc_ct.c \
	xe_guc_db_mgr.c \
	xe_guc_hwconfig.c \
	xe_guc_id_mgr.c \
	xe_guc_klv_helpers.c \
	xe_guc_log.c \
	xe_guc_pc.c \
	xe_guc_submit.c \
	xe_heci_gsc.c \
	xe_hw_engine.c \
	xe_hw_engine_class_sysfs.c \
	xe_hw_engine_group.c \
	xe_hw_fence.c \
	xe_huc.c \
	xe_irq.c \
	xe_lrc.c \
	xe_migrate.c \
	xe_mmio.c \
	xe_mocs.c \
	xe_module.c \
	xe_oa.c \
	xe_observation.c \
	xe_pat.c \
	xe_pci.c \
	xe_pcode.c \
	xe_pm.c \
	xe_preempt_fence.c \
	xe_pt.c \
	xe_pt_walk.c \
	xe_query.c \
	xe_range_fence.c \
	xe_reg_sr.c \
	xe_reg_whitelist.c \
	xe_rtp.c \
	xe_ring_ops.c \
	xe_sa.c \
	xe_sched_job.c \
	xe_step.c \
	xe_sync.c \
	xe_tile.c \
	xe_tile_sysfs.c \
	xe_trace.c \
	xe_trace_bo.c \
	xe_trace_guc.c \
	xe_ttm_sys_mgr.c \
	xe_ttm_stolen_mgr.c \
	xe_ttm_vram_mgr.c \
	xe_tuning.c \
	xe_uc.c \
	xe_uc_fw.c \
	xe_vm.c \
	xe_vram.c \
	xe_vram_freq.c \
	xe_wait_user_fence.c \
	xe_wa.c \
	xe_wa_oob.c \
	xe_wopcm.c

# SR-IOV VF pieces are unconditionally included by Linux xe-y.
SRCS+=	\
	xe_gt_sriov_vf.c \
	xe_guc_relay.c \
	xe_memirq.c \
	xe_sriov.c

SRCS+=	\
	opt_acpi.h \
	opt_drm.h \
	opt_syscons.h \
	acpi_if.h \
	bus_if.h \
	fb_if.h \
	device_if.h \
	pci_if.h \
	pci_iov_if.h \
	vnode_if.h

CLEANFILES+= ${KMOD}.ko.full ${KMOD}.ko.debug
CLEANFILES+= ${WA_GEN} ${WA_C} ${WA_H}

beforedepend: ${WA_H} ${WA_C}

${WA_GEN}: ${SRCDIR}/xe_gen_wa_oob.c
	${CC} -I${SRCDIR} -I${.CURDIR:H}/include -o ${.TARGET} ${.ALLSRC}

${WA_H} ${WA_C}: ${WA_GEN} ${WA_RULES}
	mkdir -p ${GENDIR}
	${WA_GEN} ${WA_RULES} ${WA_C} ${WA_H}

xe_wa_oob.c: ${WA_C}
	cp ${WA_C} ${.TARGET}

xe_wa_oob.h: ${WA_H}
	cp ${WA_H} ${.TARGET}

xe_wa_oob.o: xe_wa_oob.c xe_wa_oob.h

.include <bsd.kmod.mk>

.include "../linuxkpi_version.mk"
.include "../compiler_flags.mk"

CFLAGS+= -I${.CURDIR:H}/linuxkpi/gplv2/include
CFLAGS+= -I${.CURDIR:H}/linuxkpi/bsd/include
CFLAGS+= -I${SYSDIR}/compat/linuxkpi/common/include
CFLAGS+= -I${SYSDIR}/compat/linuxkpi/dummy/include

CFLAGS+= -I${.CURDIR:H}/include
CFLAGS+= -I${.CURDIR:H}/include/drm
CFLAGS+= -I${.CURDIR:H}/include/uapi
CFLAGS+= -I${SRCDIR:H:H}
CFLAGS+= -I${SRCDIR}
CFLAGS+= -I${SRCDIR}/regs
CFLAGS+= -I${SRCDIR}/instructions
CFLAGS+= -I${.CURDIR}

CFLAGS+= '-DKBUILD_MODNAME="${KMOD}"'
CFLAGS+= '-DLINUXKPI_PARAM_PREFIX=xe_' -DDRM_SYSCTL_PARAM_PREFIX=_${KMOD}
CFLAGS+= ${KCONFIG:C/(.*)/-DCONFIG_\1/}
CFLAGS+= -DCONFIG_DRM_XE

CFLAGS+= -include linux/fault-inject.h
CFLAGS+= -include linux/mmu_notifier.h
CFLAGS+= -include linux/units.h
CFLAGS+= -include linux/pci-p2pdma.h
CFLAGS+= -include linux/rwsem.h
CFLAGS+= -include linux/bitfield.h
CFLAGS+= -include linux/lockdep.h
CFLAGS+= -include linux/string_helpers.h
CFLAGS+= -include drm/drm_managed_compat.h
CFLAGS+= -include linux/component.h
CFLAGS+= -include linux/bitmap.h
CFLAGS+= -include linux/tracepoint.h

CWARNFLAGS+= -Wno-pointer-arith -Wno-format -Wno-cast-qual
CWARNFLAGS+= -Wno-unused-function -Wno-unused-variable -Wno-unused-but-set-variable
CWARNFLAGS+= -Wno-missing-prototypes -Wno-incompatible-pointer-types
CWARNFLAGS+= -Wno-incompatible-function-pointer-types
CWARNFLAGS+= -Wno-initializer-overrides
CWARNFLAGS+= -Wno-constant-logical-operand
