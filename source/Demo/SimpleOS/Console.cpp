
#include <iostream>
#include <SimpleOS/Console.hpp>

using namespace HAL;

Console::Console()
{
}

Console::~Console()
{
}

void Console::Clear() noexcept
{
}

void Console::Write(char c) noexcept
{
	std::cout << c;
}

void Console::Write(const char* src) noexcept
{
	std::cout << src;
}
