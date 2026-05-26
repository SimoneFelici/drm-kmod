# drm-kmod

The DRM drivers ported from Linux to FreeBSD using *linuxkpi*. This tree
includes the Intel xe driver for recent Intel Xe GPUs, including Battlemage
devices that use the xe DRM driver on Linux.

## Intel Arc B580 / xe branch

This fork carries experimental Intel xe support for Intel Arc B580
(`8086:e20b`) on FreeBSD 15.1-RC1. Use the `xe-b580-display-clean` branch of
this repository together with the `bmg-dmc-firmware` branch of
https://github.com/SimoneFelici/drm-kmod-firmware.

Clone both repositories explicitly from those branches:

```sh
git clone -b bmg-dmc-firmware https://github.com/SimoneFelici/drm-kmod-firmware.git
git clone -b xe-b580-display-clean https://github.com/SimoneFelici/drm-kmod.git
```

Install the firmware first. The Battlemage DMC firmware is built by the
firmware repository. The xe GuC and HuC firmware files are loaded as raw
firmware files from `/boot/firmware/xe`:

```sh
cd drm-kmod-firmware
make KMODS=i915kmsfw I915KMODS=battlemage DEBUG_FLAGS=-g SYSDIR=/usr/src/sys
sudo make KMODS=i915kmsfw I915KMODS=battlemage install DEBUG_FLAGS=-g \
    SYSDIR=/usr/src/sys KMODDIR=/boot/modules

sudo install -d -m 755 /boot/firmware/xe
sudo fetch -o /boot/firmware/xe/bmg_guc_70.bin \
    https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/xe/bmg_guc_70.bin
sudo fetch -o /boot/firmware/xe/bmg_huc.bin \
    https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/xe/bmg_huc.bin
```

Then build and install only the xe driver:

```sh
cd ../drm-kmod
make KMODS=xe DEBUG_FLAGS=-g SYSDIR=/usr/src/sys
sudo make KMODS=xe install DEBUG_FLAGS=-g SYSDIR=/usr/src/sys KMODDIR=/boot/modules
```

Load the driver manually for testing:

```sh
sudo kldload dmabuf
sudo kldload drm
sudo kldload xe
```

For boot-time loading, add the modules to rc.conf(5):

```sh
sudo sysrc kld_list+="dmabuf drm xe"
```

After loading xe, the system should expose `/dev/dri/card0` and
`/dev/dri/renderD128`. A basic KMS check is:

```sh
drm_info /dev/dri/card0
dmesg | egrep 'bmg_guc|bmg_huc|bmg_dmc|Initialized xe'
```

The kernel driver and firmware are separate from Mesa userland support. If
Mesa does not recognize `8086:e20b`, update Mesa separately.

## Installing from sources

### Requirements

You need to have the sources of FreeBSD kernel available and they MUST
correspond to the installed version of FreeBSD.

There are several ways to get them:
* by using the FreeBSD installer
* by using the `FreeBSD-src-sys` package if you use PkgBase
* by cloning the Git repository from https://git.FreeBSD.org/src.git or any mirror

By default, Makefiles expect the sources of the kernel to be in `/usr/src/sys`.
The installer and the PkgBase package will install them in that directory. If
you clone from Git, you can set `SYSDIR=/path/to/FreeBSD/src/sys` on the
make(1) command line or in the environment when compiling the drivers and their
firmwares.

### Building

```sh
make -j12 DEBUG_FLAGS=-g SYSDIR=/usr/src/sys
```

As stated in the requirements section, set `SYSDIR` to the location where you
put the FreeBSD kernel sources. The example above shows the default value.

### Installing

```sh
sudo make install DEBUG_FLAGS=-g SYSDIR=/usr/src/sys KMODDIR=/boot/modules
```

As stated in the requirements section, set `SYSDIR` to the location where you
put the FreeBSD kernel sources. The example above shows the default value.

Likewise, set `KMODDIR` to the location of the kernel you want to install the
drivers for. The example above shows the default value which is the global
directory, used by all installed kernels

> [!IMPORTANT]
> The DRM drivers MUST be compiled against the kernel sources corresponding to
> the installed kernel you want to use them with.

### GPU firmwares

DRM drivers depend on binary firmwares. They are maintained in a separate Git
repository at https://github.com/freebsd/drm-kmod-firmware.

The binary firmwares are packaged into kernel modules and loaded automatically
by the DRM drivers when needed.

The kernel modules can be compiled by following the same instructions as the
DRM drivers. The same constraint applies: use the matching kernel sources.

For Intel xe hardware, install the corresponding GuC, HuC, and DMC firmware
modules before loading the driver. The xe module can be built and installed on
its own with:

```sh
make KMODS=xe DEBUG_FLAGS=-g SYSDIR=/usr/src/sys
sudo make KMODS=xe install DEBUG_FLAGS=-g SYSDIR=/usr/src/sys KMODDIR=/boot/modules
```

Load the driver manually with `kldload xe`, or add `xe` to `kld_list` in
rc.conf(5).

## Contributing

> [!TIP]
> This part is a TL;DR version of the porting process. For the full version,
> please visit
> https://github.com/freebsd/drm-kmod/wiki/Porting-a-new-version-of-DRM-drivers-from-Linux.

1. Clone Linux:

    ```sh
    git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git /path/to/linux-src
    ```

2. Extract Linux patches:

    ```sh
    ./scripts/drmgeneratepatch \
        /path/to/linux-src \
        /path/to/patches-6.7 \
        v6.6..v6.7
    ```

3. Filter out already applied patches:

    ```sh
    ./scripts/drmcheckapplied /path/to/patches-6.7
    ```

4. Apply patches to `drm-kmod`:

    ```sh
    ./scripts/drmpatch /path/to/patches-6.7
    ```
