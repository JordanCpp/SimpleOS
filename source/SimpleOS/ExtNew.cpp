
#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/Context.hpp>

void* operator new(size_t size)
{
    return GetContext().GetAllocatorHandler()->Allocate(size);
}

void* operator new[](size_t size)
{
    return GetContext().GetAllocatorHandler()->Allocate(size);
}

void operator delete(void* ptr) noexcept
{
    return GetContext().GetAllocatorHandler()->Deallocate(ptr);
}

void operator delete[](void* ptr) noexcept
{
    return GetContext().GetAllocatorHandler()->Deallocate(ptr);
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
