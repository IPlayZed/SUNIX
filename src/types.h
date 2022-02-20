#ifndef __TYPES_H
#define __TYPES_H

#define _TRUE 1==1
#define _FALSE !_TRUE
#define LANG_C "C"
#define HIGH_BYTE 0xFF00
#define VRAM_ADDRS (uint16_t*)0xB8000

typedef void (*f_ctor)();

typedef unsigned char _boolean;

typedef char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

typedef long long int int64_t;
typedef unsigned long long int uin64_t;

#endif
