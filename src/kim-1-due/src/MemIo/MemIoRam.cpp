#include <stdio.h>
#include <stdlib.h>

#include "MemIoRam.h"
uint8_t MemIoRam::read(uint16_t address)
{
    printf("read6502 %04x\n", address);

    unsigned int offset = address - this->start_range;
    return this->data[offset];
}

void MemIoRam::write(uint16_t address, uint8_t value)
{
    unsigned int offset = address - this->start_range;
    this->data[offset] = value;
}

void MemIoRam::install(
    uint16_t start_range,
    uint16_t end_range,
    uint8_t data[])
{
    this->start_range = start_range;
    this->end_range = end_range;

    this->data = data;
}
