
#include <cassert>
#include <vector>
#include <SimpleOS/HAL/IPort.hpp>
#include <SimpleOS/PicManager.hpp>

struct Value
{
    enum
    {
        Read,
        Write
    };

    Value(uint16_t port, uint32_t data, uint8_t operation) :
        _operation(operation),
        _port(port),
        _data(data)
    {
    }

    uint8_t  _operation;
    uint16_t _port;
    uint32_t _data;
};

namespace HAL
{
    class Port final : public HAL::IPort
    {
    public:
        void Write(uint16_t port, uint8_t data)
        {
            Values.push_back(Value(port, data, Value::Write));
        }

        void Write(uint16_t port, uint16_t data)
        {
            Values.push_back(Value(port, data, Value::Write));
        }

        void Write(uint16_t port, uint32_t data)
        {
            Values.push_back(Value(port, data, Value::Write));
        }

        uint8_t Read8(uint16_t port)
        {
            return 0;
        }

        uint16_t Read16(uint16_t port)
        {
            return 0;
        }

        uint32_t Read32(uint16_t port)
        {
            return 0;
        }

        void Wait()
        {
            Values.push_back(Value(0x80, 0, Value::Read));
        }

        std::vector<Value> Values;
    };
}

int main()
{
    HAL::Port testPort;
    PicManager picManager(&testPort);

    picManager.Remap(0, 1);

    std::vector<Value> TrueValues;

    TrueValues.push_back(Value(PicManager::MASTER_PIC_COMMAND, PicManager::ICW1_INIT, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));
    TrueValues.push_back(Value(PicManager::SLAVE_PIC_COMMAND, PicManager::ICW1_INIT, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));

    TrueValues.push_back(Value(PicManager::MASTER_PIC_DATA, 0, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));
    TrueValues.push_back(Value(PicManager::SLAVE_PIC_DATA, 1, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));

    TrueValues.push_back(Value(PicManager::MASTER_PIC_DATA, 0x04, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));
    TrueValues.push_back(Value(PicManager::SLAVE_PIC_DATA, 0x02, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));

    TrueValues.push_back(Value(PicManager::MASTER_PIC_DATA, PicManager::ICW4_8086, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));
    TrueValues.push_back(Value(PicManager::SLAVE_PIC_DATA, PicManager::ICW4_8086, Value::Write));
    TrueValues.push_back(Value(0x80, 0, Value::Read));

    TrueValues.push_back(Value(PicManager::MASTER_PIC_DATA, 0xFF, Value::Write));
    TrueValues.push_back(Value(PicManager::SLAVE_PIC_DATA, 0xFF, Value::Write));

    for (size_t i = 0; i < TrueValues.size(); i++)
    {
        assert(TrueValues[i]._operation == testPort.Values[i]._operation);
        assert(TrueValues[i]._port      == testPort.Values[i]._port);
        assert(TrueValues[i]._data      == testPort.Values[i]._data);
    }

	return 0;
}
