
#include <SimpleOS/Port.hpp>
#include <SimpleOS/PicManager.hpp>

void PicManager::Remap(uint8_t master, uint8_t slave) const 
{
    Port::Write(MASTER_PIC_COMMAND, ICW1_INIT);
    Port::Wait();
    Port::Write(SLAVE_PIC_COMMAND, ICW1_INIT);
    Port::Wait();

    Port::Write(MASTER_PIC_DATA, master);
    Port::Wait();
    Port::Write(SLAVE_PIC_DATA, slave);
    Port::Wait();

    Port::Write(MASTER_PIC_DATA, static_cast<uint8_t>(0x04));
    Port::Wait();
    Port::Write(SLAVE_PIC_DATA, static_cast<uint8_t>(0x02));
    Port::Wait();

    Port::Write(MASTER_PIC_DATA, ICW4_8086);
    Port::Wait();
    Port::Write(SLAVE_PIC_DATA, ICW4_8086);
    Port::Wait();

    Port::Write(MASTER_PIC_DATA, static_cast<uint8_t>(0xFF));
    Port::Write(SLAVE_PIC_DATA, static_cast<uint8_t>(0xFF));
}

void PicManager::Eoi(uint8_t number) const 
{
    if (number >= 0x28) 
    {
        Port::Write(SLAVE_PIC_COMMAND, static_cast<uint8_t>(0x20));
    }

    Port::Write(MASTER_PIC_COMMAND, static_cast<uint8_t>(0x20));
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

    value = Port::Read<uint8_t>(port);

    value &= ~(1 << irqLine);

    Port::Write(port, value);
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

    value = Port::Read<uint8_t>(port);

    value |= (1 << irqLine);

    Port::Write(port, value);
}