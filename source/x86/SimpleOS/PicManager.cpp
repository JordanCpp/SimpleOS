
#include <SimpleOS/Port.hpp>
#include <SimpleOS/PicManager.hpp>

PicManager::PicManager(HAL::IPort* port) :
    _port(port)
{
}

void PicManager::Remap(uint8_t master, uint8_t slave) const
{
    _port->Write(MASTER_PIC_COMMAND, ICW1_INIT);
    _port->Wait();
    _port->Write(SLAVE_PIC_COMMAND, ICW1_INIT);
    _port->Wait();

    _port->Write(MASTER_PIC_DATA, master);
    _port->Wait();
    _port->Write(SLAVE_PIC_DATA, slave);
    _port->Wait();

    _port->Write(MASTER_PIC_DATA, static_cast<uint8_t>(0x04));
    _port->Wait();
    _port->Write(SLAVE_PIC_DATA, static_cast<uint8_t>(0x02));
    _port->Wait();

    _port->Write(MASTER_PIC_DATA, ICW4_8086);
    _port->Wait();
    _port->Write(SLAVE_PIC_DATA, ICW4_8086);
    _port->Wait();

    _port->Write(MASTER_PIC_DATA, static_cast<uint8_t>(0xFF));
    _port->Write(SLAVE_PIC_DATA, static_cast<uint8_t>(0xFF));
}

void PicManager::Eoi(uint8_t number) const 
{
    if (number >= 0x28) 
    {
        _port->Write(SLAVE_PIC_COMMAND, static_cast<uint8_t>(0x20));
    }

    _port->Write(MASTER_PIC_COMMAND, static_cast<uint8_t>(0x20));
}

void PicManager::Unmask(uint8_t irqLine) const 
{
    uint16_t port;
    uint8_t value;
    if (irqLine < 8) 
    {
        port = MASTER_PIC_DATA;
    }
    else 
    {
        port = SLAVE_PIC_DATA;
        irqLine -= 8;
    }

    value = _port->Read8(port);

    value &= ~(1 << irqLine);

    _port->Write(port, value);
}

void PicManager::Mask(uint8_t irqLine) const 
{
    uint16_t port;
    uint8_t value;

    if (irqLine < 8) 
    {
        port = MASTER_PIC_DATA;
    }
    else 
    {
        port = SLAVE_PIC_DATA;
        irqLine -= 8;
    }

    value = _port->Read8(port);

    value |= (1 << irqLine);

    _port->Write(port, value);
}