typedef unsigned short uint16_t;
typedef void (*ctor)();

#define HIGH_BYTE 0xFF00
#define VRAM_ADDRS (uint16_t*)0xb8000
#define MESSAGE (char*)"Kernel main test"
#define TRUE 1==1
#define FALSE !TRUE
#define LANG_C "C"


extern LANG_C ctor start_ctors;
extern LANG_C ctor end_ctors;


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

extern LANG_C void call_ctors()
{
	for(ctor* i = &start_ctors; i != (ctor*)end_ctors; i++)
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
extern LANG_C void kernel_main(void* multiboot_struct, unsigned int multiboot_flag) {
    printf(MESSAGE);
    while(TRUE);
}
