
#include <SimpleOS/Console.hpp>

using namespace HAL;

Console::Console() :
    _cursorX(0),
    _cursorY(0),
    _buffer((uint16_t*)Address)
{
}

Console::~Console()
{
}

void Console::Clear() noexcept
{
    for (size_t i = 0; i < Width * Heigth; i++)
    {
        Write(' ', i % Width, i / Width);
    }

    _cursorX = 0;
    _cursorY = 0;
}

void Console::Write(char c) noexcept
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

        if (_cursorX >= Width)
        {
            _cursorX = 0;
            _cursorY++;
        }
    }

    if (_cursorY >= Heigth)
    {
        _cursorY = Heigth - 1;
    }
}

void Console::Write(const char* src) noexcept
{
    while (*src)
    {
        Write(*src++);
    }
}

void Console::Write(char c, uint8_t x, uint8_t y) noexcept
{
    _buffer[y * Width + x] = (0x0F << 8) | c;
}
