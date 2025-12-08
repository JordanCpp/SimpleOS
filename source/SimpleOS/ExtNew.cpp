
#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/Context.hpp>

void* operator new(size_t size)
{
    return GetAllocatorHandler()->Allocate(size);
}

void* operator new[](size_t size)
{
    return GetAllocatorHandler()->Allocate(size);
}

void operator delete(void* ptr) noexcept
{
    return GetAllocatorHandler()->Deallocate(ptr);
}

void operator delete[](void* ptr) noexcept
{
    return GetAllocatorHandler()->Deallocate(ptr);
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
