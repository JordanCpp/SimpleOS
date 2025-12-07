
#pragma once

#include <cstdint>

class InterruptRegister
{
public:
    InterruptRegister();
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

class Interrupt 
{
public:
    Interrupt();
    void Handler(void* handler);
private:
    uint16_t  _offsetLow;
    uint16_t  _selector;
    uint8_t   _zero;
    uint8_t   _typeAttr;
    uint16_t  _offsetHigh;
} __attribute__((packed));
