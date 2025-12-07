
module;

#include <cstdint>
#include <memory>

export module Kernel;

import HAL.Platform;
import HAL.BumpAllocator;
import HAL.BaseAddress;
import HAL.Pmm;
import HAL.IConsole;
import HAL.Console;
import String;

struct NoDelete
{
	void operator()(void* ptr)
	{
		(void)ptr;
	}
};

export class Kernel
{
public:
	Kernel();
	~Kernel();
	void Run();
private:
	Platform _platform;
	alignas(HAL::Pmm)      uint8_t _pmmBuffer[sizeof(HAL::Pmm)];
	alignas(BumpAllocator) uint8_t _allocatorBuffer[sizeof(BumpAllocator)];
	HAL::IPmm* _pmm;
	HAL::IAllocator* _allocator;
	std::unique_ptr<HAL::IConsole, NoDelete> _console;
	HAL::IKeyboard* _keyboard;
};

using namespace HAL;

export HAL::IAllocator* MainAllocator = nullptr;

Kernel::Kernel() :
	_pmm(nullptr),
	_allocator(nullptr),
	_console(nullptr),
	_keyboard(nullptr)
{
	_pmm       = new (_pmmBuffer)       Pmm(BaseAddress());
	_allocator = new (_allocatorBuffer) BumpAllocator(_pmm);

	MainAllocator = _allocator;

	_console = std::unique_ptr<HAL::IConsole, NoDelete>(new Console());

	_keyboard = _platform.GetKeyboard();
}

Kernel::~Kernel()
{
	if (_allocator)
	{
		_allocator->~IAllocator();
	}

	if (_pmm)
	{
		_pmm->~IPmm();
	}
}

void Kernel::Run()
{
	OS::String str1 = "Running ";
	str1 += "SimpleOS!";

	_console->Write(str1.c_str());
	_console->Write('\n');

	while (true)
	{
		if (_keyboard->ReadKey() != 0)
		{
			_console->Write("Press key");
			_console->Write('\n');
		}
	}
}
