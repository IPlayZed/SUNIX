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
            
            public:
                SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t access);
                uint32_t GetBase();
                uint32_t GetLimit();

        } __attribute__((packed));

        SegmentDescriptor nullSegmentSelector;
        SegmentDescriptor unusedSegmentSelector;
        // TODO: This is only an MVP, there should NOT be only 1 code and data segment,
        //       right now they spread through the whole memory, but this is a huge
        //       security vulnerability.
        SegmentDescriptor codeSegmentSelector;
        SegmentDescriptor dataSegmentSelector;

        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        
        uint16_t GetCodeSegmentSelectorOffset();
        uint16_t GetDataSegmentSelectorOffset();

};

#endif
