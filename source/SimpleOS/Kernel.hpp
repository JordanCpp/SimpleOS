
#pragma once

#include <memory>
#include <SimpleOS/Pmm.hpp>
#include <SimpleOS/Console.hpp>
#include <SimpleOS/Platform.hpp>
#include <SimpleOS/BumpAllocator.hpp>

struct NoDelete
{
	void operator()(void* ptr)
	{
		(void)ptr;
	}
};

class Kernel
{
public:
	Kernel();
	~Kernel();
	void Run();
private:
	Platform _platform;
	alignas(HAL::Pmm)      uint8_t _pmmBuffer       [sizeof(HAL::Pmm)];
	alignas(BumpAllocator) uint8_t _allocatorBuffer [sizeof(BumpAllocator)];
	HAL::IPmm*                     _pmm;
	HAL::IAllocator*               _allocator;
	std::unique_ptr<HAL::IConsole, NoDelete> _console;
	HAL::IKeyboard* _keyboard;
};
