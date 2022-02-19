#include "types.h"

#define MESSAGE (char*)"Kernel main test "

extern LANG_C f_ctor start_ctors;
extern LANG_C f_ctor end_ctors;


/* As we do not use glibc, we must write our very basic implementation of print.
 * This implementation only support putting ASCII characters on the screen, with black background and white text.
 * The idea is that adressing VRAM_ADDRS will translate to the GPU hardware putting text on VGA output.
 * The high byte is the color code, which we leave the default (hence the black-white color of the output) and
 * the low byte is the ASCII character. By writing on this adress following this idea, we can put text on the screen
 * in a very basic manner.
 * 
 * */
void printf(char* str) 
{ 
 uint16_t* vram = VRAM_ADDRS;
 
 for(int i = 0; str[i] != '\0'; ++i) {
     vram[i] = (uint16_t)(vram[i] & HIGH_BYTE) | str[i];
 }
}

/* For composite object static/global objects (like class instances) we must call the compiler
 * generated constructors.
 * We just iterate through them.
 * */
extern LANG_C void call_ctors()
{
	for(f_ctor* i = &start_ctors; i != &end_ctors; i++)
	{
		(*i)();
	}	
}

/* We take the multiboot structure and multiboot flag value which we have pushed with
 *      push %eax
 *      push %ebx
 * to the stack. The multiboot structure can be used for kernel operation, while
 * the multiboot flag can be used to make sure the enviroment is indeed multiboot.
 * */
extern LANG_C void kernel_main(void* multiboot_struct, uint32_t multiboot_flags) {
    printf(MESSAGE);
    while(_TRUE);
}
