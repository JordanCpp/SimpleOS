
#include <SimpleOS/Port.hpp>

using namespace HAL;

void Port::Write(uint16_t port, uint8_t data)
{
    asm volatile("outb %0, %1" : : "a"(data), "dN"(port));
}

void Port::Write(uint16_t port, uint16_t data)
{
    asm volatile("outw %0, %1" : : "a"(data), "dN"(port));
}

void Port::Write(uint16_t port, uint32_t data)
{
    asm volatile("outl %0, %1" : : "a"(data), "dN"(port));
}

uint8_t Port::Read8(uint16_t port)
{
    uint8_t result = 0;

    asm volatile("inb %1, %0" : "=a"(result) : "dN"(port));
    
    return result;
}

uint16_t Port::Read16(uint16_t port)
{
    uint16_t result = 0;

    asm volatile("inw %1, %0" : "=a"(result) : "dN"(port));

    return result;
}

uint32_t Port::Read32(uint16_t port)
{
    uint32_t result = 0;

    asm volatile("inl %1, %0" : "=a"(result) : "dN"(port));

    return result;
}

void Port::Wait()
{
    Read16(0x80);
}
