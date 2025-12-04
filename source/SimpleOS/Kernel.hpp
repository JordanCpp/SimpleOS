
#pragma once

#include <SimpleOS/Pmm.hpp>
#include <SimpleOS/Console.hpp>
#include <SimpleOS/BumpAllocator.hpp>

class Kernel
{
public:
	Kernel();
	~Kernel();
	void Run();
private:
	alignas(HAL::Console)  uint8_t _consoleBuffer   [sizeof(HAL::Console)];
	alignas(HAL::Pmm)      uint8_t _pmmBuffer       [sizeof(HAL::Pmm)];
	alignas(BumpAllocator) uint8_t _allocatorBuffer [sizeof(BumpAllocator)];
	HAL::IConsole*   _console;
	HAL::IPmm*       _pmm;
	HAL::IAllocator* _allocator;
};
