
#include <iostream>
#include <SimpleOS/Console.hpp>

using namespace HAL;

Console::Console()
{
}

Console::~Console()
{
}

void Console::Clear()
{
}

void Console::Write(char c)
{
	std::cout << c;
}

void Console::Write(const char* src)
{
	std::cout << src;
}
