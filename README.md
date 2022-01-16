# SUNIX by IPlayZed
This is a hobbyist project focused on creating a UNIX-like kernel.
The main goal of the project is to be multiboot compliant and bootable through
a bootloader supporting the multiboot standard.
The architecture in mind now is x86 and it is assumed that the system is in legacy BIOS mode.

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