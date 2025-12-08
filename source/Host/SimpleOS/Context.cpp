
#include <SimpleOS/Context.hpp>

Context::Context() :
	_allocator(nullptr)
{
}

HAL::IAllocator* Context::GetAllocatorHandler()
{
	return _allocator;
}

void Context::SetAllocatorHandler(HAL::IAllocator* allocator)
{
	_allocator = allocator;
}

Context globalContext;

Context& GetContext()
{
	return globalContext;
}
