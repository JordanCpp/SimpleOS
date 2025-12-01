
#include <SimpleOS/Console.hpp>

using namespace HAL;

Console::Console() :
    _cursorX(0),
    _cursorY(0),
    _buffer((uint16_t*)0xB8000)
{
}

Console::~Console()
{
}

void Console::Clear()
{
    for (size_t i = 0; i < 80 * 25; i++) 
    {
        Write(' ', i % 80, i / 80);
    }

    _cursorX = 0;
    _cursorY = 0;
}

void Console::Write(char c)
{
    if (c == '\n') 
    {
        _cursorX = 0;
        _cursorY++;
    }
    else 
    {
        Write(c, _cursorX, _cursorY);
        _cursorX++;

        if (_cursorX >= 80)
        {
            _cursorX = 0;
            _cursorY++;
        }
    }

    if (_cursorY >= 25)
    {
        _cursorY = 24;
    }
}

void Console::Write(const char* src)
{
    while (*src)
    {
        Write(*src++);
    }
}

void Console::Write(char c, uint8_t x, uint8_t y)
{
    _buffer[y * 80 + x] = (0x0F << 8) | c;
}
