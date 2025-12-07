
#include <SimpleOS/InterruptManager.hpp>

extern "C" void InterruptHandler(int number);

InterruptManager::InterruptManager()
{
	_register.limit = sizeof(_table) - 1;
	_register.base  = reinterpret_cast<uint32_t>(&_table);

	for (auto& i : _table)
	{
		i.Handler(reinterpret_cast<void*>(InterruptHandler));
	}
}

void InterruptManager::Load()
{
	asm volatile("lidt %0" : : "m"(_register));
}

void InterruptManager::Enable()
{
	asm volatile("sti");
}

void InterruptManager::Set(uint8_t index, void* handler)
{
	_table[index].Handler(handler);
}
