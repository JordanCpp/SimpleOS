
#include <SimpleOS/Kernel.hpp>

using namespace HAL;

Kernel::Kernel() :
	_console(nullptr)
{
	_console = new (_consoleBuffer) Console();
}

Kernel::~Kernel()
{
	if (_console)
	{
		_console->~IConsole();
	}
}

void Kernel::Run()
{
	while (true)
	{
		_console->Write("Running SimpleOS\n");
	}
}
