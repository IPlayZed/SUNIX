# compiler variables
.set MULTIBOOT_FLAG, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MULTIBOOT_FLAG + FLAGS)

.section .multiboot
    .long MULTIBOOT_FLAG
    .long FLAGS
    .long CHECKSUM

.section .text # the program section 
.extern kernel_main # We would like to use an external call to the main kernel function. This assumes, that the linker will take care of providing this symbol. 
.extern call_ctors
.global loader

loader:
    mov $kernel_stack_ptr, %esp # set stack pointer, as kernel_main is a cpp program and it expects the stack pointer to be set

	call call_ctors
	
    push %eax # The (GRUB2) bootloader stores the multiboot structure's RAM adress in the AX register during loading the kernel of choice, which contains valuable information, like the size of the RAM. We should push this to the stack in order to access it later.
    push %ebx # The (GRUB2) bootloader stores the MULTIBOOT_FLAG value in the BX register.
    call kernel_main 
_stop:
    cli
    hlt
    jmp _stop
    
.section .bss # the data section 

.space 2*1021*1024 # as the stack grows downwards we do not want to overwrite the kernel loaded in by the bootloader 
kernel_stack_ptr:
