
#pragma once

#include <SimpleOS/HAL/IPort.hpp>

namespace HAL
{
    class Port final: public HAL::IPort
    {
    public:
        void Write(uint16_t port, uint8_t data);
        void Write(uint16_t port, uint16_t data);
        void Write(uint16_t port, uint32_t data);
        uint8_t Read8(uint16_t port);
        uint16_t Read16(uint16_t port);
        uint32_t Read32(uint16_t port);
        void Wait();
    };
}
