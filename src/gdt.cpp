#include "gdt.h"

GlobalDescriptorTable::GlobalDescriptorTable()
: nullSegmentSelector(0, 0, 0), unusedSegmentSelector(0, 0, 0),
codeSegmentSelector(0, _64_MEGABYTES, CSS_FLAGS),
dataSegmentSelector(0, _64_MEGABYTES, DSS_FLAGS) {

    uint32_t expectedBytes[EXPECTED_BYTES_NUM];
    expectedBytes[GDT_ADDRESS] = (uint32_t)this;
    expectedBytes[SEGMENT_INTEGER_HIGH_BYTES] = sizeof(GlobalDescriptorTable) << HIGH_BYTES_LSHIFT;

    asm volatile("lgdt (%0)": :"p" (((uint8_t*) expectedBytes+2)));
}

// TODO: Unload the GDT.
GlobalDescriptorTable::~GlobalDescriptorTable(){}

uint16_t GlobalDescriptorTable::GetDataSegmentSelectorOffset(){
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
}

uint16_t GlobalDescriptorTable::GetCodeSegmentSelectorOffset() {
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags) {
    uint8_t* targetSegmentDescriptor = (uint8_t*)this;
    if (limit <= SMALL_LIMIT_16) {
        targetSegmentDescriptor[SEGMENT_DESCRIPTOR_ACCESS] = 0x40; 
    }
    else {
        // TODO
    }
    
}
