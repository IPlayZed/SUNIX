/* We take the multiboot structure and multiboot flag value which we have pushed with
 *      push %eax
 *      push %ebx
 * to the stack. The multiboot structure can be used for kernel operation, while
 * the multiboot flag can be used to make sure the enviroment is indeed multiboot.
 * */
void kernel_main(void* multiboot_struct, unsigned int multiboot_flag) {
    printf("Kernel main test");
    while(1);
}
