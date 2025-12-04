
#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/Hal/HalAllocator.hpp>

extern HAL::IAllocator* MainAllocator;

void* operator new(size_t size)
{
    return MainAllocator->Allocate(size);
}

void* operator new[](size_t size)
{
    return MainAllocator->Allocate(size);
}

void operator delete(void* ptr) noexcept
{
    return MainAllocator->Deallocate(ptr);
}

void operator delete[](void* ptr) noexcept
{
    return MainAllocator->Deallocate(ptr);
}

void operator delete(void* ptr, size_t size) noexcept
{
    (void)ptr;
    (void)size;
}

void operator delete[](void* ptr, size_t size) noexcept
{
    (void)ptr;
    (void)size;
}
