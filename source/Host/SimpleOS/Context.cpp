
#include <SimpleOS/Context.hpp>

HAL::IAllocator* globalAllocator  = nullptr;

HAL::IAllocator* GetAllocatorHandler()
{
	return globalAllocator;
}

void SetAllocatorHandler(HAL::IAllocator* allocator)
{
	globalAllocator = allocator;
}
