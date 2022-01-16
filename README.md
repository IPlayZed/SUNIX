# SUNIX by IPlayZed
This is a hobbyist project focused on creating a UNIX-like kernel.
The main goal of the project is to be multiboot compliant and bootable through
a bootloader supporting the multiboot standard.
The architecture in mind now is x86 and it is assumed that the system is in legacy BIOS mode.

## Build and install

### Environment

- Ubuntu 20.04
- Install dependencies: `sudo apt install g++ binutils libc6-dev-i386 make`
- Optional dependencies (if you plan to boot the kernel with Qemu): `sudo apt qemu-system-x86`

### Boot with Qemu 

Most will prefer this.

1. To build and install issue command `make install` in `src`.
2. To boot the kernel with Qemu issue `qemu-system-i386 --kernel mykernel.bin` in `out`.

### Boot on real hardware with GRUB2

This will NOT break your system in any way ;).
If you want to run it on bare metal, you must have GRUB2 installed.

The kernel binary by default is installed into `/boot` with `make grubinstall`.
There are multiple ways to add it as an entry, but the easy and dirty way is to add it
explicitly as a custom binary into the generated GRUB script, which is located at
`/boot/grub/grub.cfg`.

For instance you could add the following at the *END OF THE FILE*:

```sh
### BEGIN MYKERNEL ###

menuentry 'SUNIX'{
	multiboot /boot/mykernel.bin
	boot
}

### END MYKERNEL ###
```

## Main goals
This list is not final and may be modified freely throughout the evolution of the project.
 - [x] Take control over from GRUB2.
 - [x] Booot into a loop.
 - [x] Write out some text.
 - [ ] Write out decimals.
 - [ ] Write out hexadecimals.
 - [ ] Output to a serial port.
 - [ ] Interrupt handling system.
 - [ ] Exception handling system.
 - [ ] Dump the contents of the register.
 - [ ] Dump the adress in case of a fault.
 - [ ] Plan a physical memory map.
 - [ ] Plan a virtual memory map.
 - [ ] Implement "malloc".
 - [ ] Implement "free".
 - [ ] Give control over to init.