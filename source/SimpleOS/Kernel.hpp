
#pragma once

#include <SimpleOS/Console.hpp>

class Kernel
{
public:
	Kernel();
	~Kernel();
	void Run();
private:
	alignas(HAL::Console) uint8_t _consoleBuffer[sizeof(HAL::Console)];
	HAL::IConsole* _console;
};
