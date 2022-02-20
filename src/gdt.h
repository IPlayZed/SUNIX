#ifndef __GDT_H
#define __GDT_H

#include "types.h"
class GlobalDescriptorTable {
    public:
    
        /*
        b: The base/pointer to the code segment.
        l: The data segment limit.
        a: Access rights
        f: Flags.
                   b   f   l   a   b   b    l
        bits:    | 8 | 4 | 4 | 8 | 8 | 16 | 16 |
        */
        class SegmentDescriptor {
            private:

                uint16_t limit_lowbytes;
                uint16_t base_lowbytes;
                uint8_t base_highbyte_low;
                uint8_t access;
                uint8_t flags_and_limit_high_halfbyte;
                uint8_t base_highbyte_high;
        } __attribute__((packed));
};

#endif
