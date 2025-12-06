
#include <SimpleOS/Kernel.hpp>
#include <SimpleOS/STL/String.hpp>
#include <SimpleOS/BumpAllocator.hpp>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

using namespace HAL;

HAL::IAllocator* MainAllocator = nullptr;

Kernel::Kernel() :
	_pmm(nullptr),
	_allocator(nullptr),
	_console(nullptr)
{
	_pmm       = new (_pmmBuffer)       Pmm(BaseAddress());
	_allocator = new (_allocatorBuffer) BumpAllocator(_pmm);

	MainAllocator = _allocator;

	_console = std::unique_ptr<HAL::IConsole, NoDelete>(new Console());
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

	while (true)
	{
		_console->Write(str1.c_str());
		_console->Write('\n');
	}
}
