
#pragma once

#include <SimpleOS/HAL/IPort.hpp>

class PicManager
{
public:
    PicManager(HAL::IPort* port);
    static constexpr uint16_t MASTER_PIC_COMMAND = 0x20;
    static constexpr uint16_t MASTER_PIC_DATA    = 0x21;
    static constexpr uint16_t SLAVE_PIC_COMMAND  = 0xA0;
    static constexpr uint16_t SLAVE_PIC_DATA     = 0xA1;
    static constexpr uint8_t  ICW1_INIT          = 0x11;
    static constexpr uint8_t  ICW4_8086          = 0x01;
    void Remap(uint8_t master, uint8_t slave) const;
    void Eoi(uint8_t number) const;
    void Unmask(uint8_t irq_line) const;
    void Mask(uint8_t irq_line) const;
private:
    HAL::IPort* _port;
};
