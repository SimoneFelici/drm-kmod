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
	${SRCDIR}/display \
	${SRCDIR}/display/ext \
	${.CURDIR:H}/drivers/gpu/drm/i915/display \
	${.CURDIR:H}/drivers/gpu/drm/i915/soc \
	${.CURDIR:H}/drivers/video \
	${GENDIR}

.PATH: ${.CURDIR:H}/drivers/gpu/drm/ttm
.PATH: ${.CURDIR:H}/drivers/gpu/drm

KMOD=	xe
KMODDEPS=	dmabuf drm ttm

EXPORT_SYMS=	YES

SRCS=	\
	xe_freebsd_stubs.c \
	xe_bb.c \
	xe_bo.c \
	xe_bo_evict.c \
	xe_devcoredump.c \
	xe_debugfs.c \
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
	xe_gt_stats.c \
	xe_gt_debugfs.c \
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
	xe_guc_debugfs.c \
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
	xe_huc_debugfs.c \
	xe_hmm.c \
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
	xe_uc_debugfs.c \
	xe_uc_fw.c \
	xe_vm.c \
	xe_vram.c \
	xe_vram_freq.c \
	xe_wait_user_fence.c \
	xe_wa.c \
	xe_wopcm.c

.if ${KCONFIG:MDRM_XE_DISPLAY} != ""
SRCS+= \
	i915_irq.c \
	i915_utils.c \
	intel_fb_bo.c \
	intel_fbdev_fb.c \
	xe_display.c \
	xe_display_misc.c \
	xe_display_rps.c \
	xe_display_wa.c \
	xe_dsb_buffer.c \
	xe_fb_pin.c \
	xe_hdcp_gsc.c \
	xe_plane_initial.c \
	xe_tdf.c \
	icl_dsi.c \
	intel_acpi.c \
	intel_alpm.c \
	intel_atomic.c \
	intel_atomic_plane.c \
	intel_audio.c \
	intel_backlight.c \
	intel_bios.c \
	intel_bw.c \
	intel_cdclk.c \
	intel_color.c \
	intel_combo_phy.c \
	intel_connector.c \
	intel_crtc.c \
	intel_crtc_state_dump.c \
	hdmi.c \
	intel_cursor.c \
	intel_cx0_phy.c \
	intel_ddi.c \
	intel_ddi_buf_trans.c \
	intel_display.c \
	intel_display_device.c \
	intel_display_driver.c \
	intel_display_irq.c \
	intel_display_params.c \
	intel_display_power.c \
	intel_display_power_map.c \
	intel_display_power_well.c \
	intel_display_wa.c \
	intel_dkl_phy.c \
	intel_dmc.c \
	intel_dp.c \
	intel_dp_aux.c \
	intel_dp_aux_backlight.c \
	intel_dp_hdcp.c \
	intel_dp_link_training.c \
	intel_dp_mst.c \
	intel_dpll.c \
	intel_dpll_mgr.c \
	intel_dpt_common.c \
	intel_drrs.c \
	intel_dsb.c \
	intel_dsi.c \
	intel_dsi_dcs_backlight.c \
	intel_dsi_vbt.c \
	intel_encoder.c \
	intel_fb.c \
	intel_fbc.c \
	intel_fdi.c \
	intel_fifo_underrun.c \
	intel_frontbuffer.c \
	intel_global_state.c \
	intel_gmbus.c \
	intel_hdcp.c \
	intel_hdcp_gsc_message.c \
	intel_hdmi.c \
	intel_hotplug.c \
	intel_hotplug_irq.c \
	intel_hti.c \
	intel_link_bw.c \
	intel_lspcon.c \
	intel_modeset_lock.c \
	intel_modeset_setup.c \
	intel_modeset_verify.c \
	intel_opregion.c \
	intel_panel.c \
	intel_pch.c \
	intel_pmdemand.c \
	intel_pps.c \
	intel_psr.c \
	intel_qp_tables.c \
	intel_quirks.c \
	intel_snps_phy.c \
	intel_tc.c \
	intel_vblank.c \
	intel_vdsc.c \
	intel_vga.c \
	intel_vrr.c \
	intel_dmc_wl.c \
	intel_dram.c \
	intel_wm.c \
	skl_scaler.c \
	skl_universal_plane.c \
	skl_watermark.c
.endif

# SR-IOV VF pieces are unconditionally included by Linux xe-y.
SRCS+=	\
	xe_gt_sriov_vf.c \
	xe_gt_sriov_vf_debugfs.c \
	xe_guc_relay.c \
	xe_memirq.c \
	xe_sriov.c


# Temporary: link TTM directly into xe.ko until KLD symbol export/dependency is fixed.
CFLAGS+= -DXE_EMBED_TTM
SRCS+= \
	ttm_bo.c \
	ttm_bo_util.c \
	ttm_bo_vm.c \
	ttm_execbuf_util.c \
	ttm_module.c \
	ttm_pool.c \
	ttm_device.c \
	ttm_sys_manager.c \
	ttm_range_manager.c \
	ttm_resource.c \
	ttm_tt.c \
	drm_gem_ttm_helper.c

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
CFLAGS+= -I${SRCDIR}/compat-i915-headers
CFLAGS+= -I${SRCDIR}/display
CFLAGS+= -I${SRCDIR}/display/ext
CFLAGS+= -I${.CURDIR:H}/drivers/gpu/drm/i915/display
CFLAGS+= -I${.CURDIR:H}/drivers/gpu/drm/i915/soc
CFLAGS+= -Ddrm_i915_gem_object=xe_bo
CFLAGS+= -Ddrm_i915_private=xe_device
CFLAGS+= -I${SRCDIR}/regs
CFLAGS+= -I${SRCDIR}/instructions
CFLAGS+= -I${.CURDIR}

CFLAGS+= '-DKBUILD_MODNAME="${KMOD}"'
CFLAGS+= '-DLINUXKPI_PARAM_PREFIX=xe_' -DDRM_SYSCTL_PARAM_PREFIX=_${KMOD}
CFLAGS+= ${KCONFIG:C/(.*)/-DCONFIG_\1/}
CFLAGS+= -DCONFIG_DRM_XE
CFLAGS+= -DCONFIG_DRM_XE_FORCE_PROBE='"*"'

CFLAGS+= -include linux/fault-inject.h
CFLAGS+= -include linux/mmu_notifier.h
CFLAGS+= -include linux/units.h
CFLAGS+= -include linux/pci-p2pdma.h
CFLAGS+= -include linux/pm.h
CFLAGS+= -include linux/rwsem.h
CFLAGS+= -include linux/bitfield.h
CFLAGS+= -include linux/lockdep.h
CFLAGS+= -include linux/string_helpers.h
CFLAGS+= -include drm/drm_managed_compat.h
CFLAGS+= -include linux/component.h
CFLAGS+= -include linux/perf_event.h
CFLAGS+= -include linux/uuid.h
CFLAGS+= -include linux/mm.h
CFLAGS+= -include linux/anon_inodes.h
CFLAGS+= -include linux/idr.h
CFLAGS+= -include linux/align.h
CFLAGS+= -include linux/acpi.h
CFLAGS+= -include linux/kunit.h
CFLAGS+= -include linux/kthread.h
CFLAGS+= -include linux/ioport.h
CFLAGS+= -include linux/io.h
CFLAGS+= -include linux/sizes.h
CFLAGS+= -include linux/errno.h
CFLAGS+= -include linux/bitmap.h
CFLAGS+= -include linux/tracepoint.h

CWARNFLAGS+= -Wno-pointer-arith -Wno-format -Wno-cast-qual
CWARNFLAGS+= -Wno-unused-function -Wno-unused-variable -Wno-unused-but-set-variable
CWARNFLAGS+= -Wno-missing-prototypes -Wno-incompatible-pointer-types
CWARNFLAGS+= -Wno-incompatible-function-pointer-types
CWARNFLAGS+= -Wno-initializer-overrides
CWARNFLAGS+= -Wno-constant-logical-operand

CWARNFLAGS+= -Wno-macro-redefined
