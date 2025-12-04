

#include <SimpleOS/STL.hpp>
#include <SimpleOS/Kernel.hpp>
#include <SimpleOS/BumpAllocator.hpp>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

using namespace HAL;

HAL::IAllocator* MainAllocator = nullptr;

Kernel::Kernel() :
	_console(nullptr),
	_pmm(nullptr),
	_allocator(nullptr)
{
	_console   = new (_consoleBuffer)   Console();
	_pmm       = new (_pmmBuffer)       Pmm(BaseAddress());
	_allocator = new (_allocatorBuffer) BumpAllocator(_pmm);

	MainAllocator = _allocator;
}

Kernel::~Kernel()
{
	if (_console)
	{
		_console->~IConsole();
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

	while (true)
	{
		_console->Write(str1.c_str());
		_console->Write('\n');
	}
}
