#include "gdt.h"

#define _64_MEGABYTES 64*1024*1024
#define CSS_FLAGS 0x9A
#define DSS_FLAGS 0x92
#define EXPECTED_BYTES_NUM 2
#define GDT_ADDRESS 0
#define SEGMENT_INTEGER_HIGH_BYTES 1
#define HIGH_BYTES_LSHIFT 16

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
