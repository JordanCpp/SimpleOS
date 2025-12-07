
#include <SimpleOS/Interrupt.hpp>

InterruptRegister::InterruptRegister() :
    limit(0),
    base(0)
{
}

Interrupt::Interrupt() :
    _offsetLow(0),
    _selector(0),
    _zero(0),
    _typeAttr(0),
    _offsetHigh(0)
{
}

void Interrupt::Handler(void* handler)
{
    uint32_t address = reinterpret_cast<uint32_t>(handler);
    _offsetLow       = static_cast<uint16_t>(address & 0xFFFF);
    _offsetHigh      = static_cast<uint16_t>((address >> 16) & 0xFFFF);
    _selector        = 0x08;
    _typeAttr        = 0x8E;
    _zero            = 0;
}
