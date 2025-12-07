
module;

#include <cstddef>

export module ExtNew;

import HAL.IAllocator;
import Kernel;

export void* operator new(size_t size);
export void* operator new[](size_t size);

export void operator delete(void* ptr) noexcept;
export void operator delete[](void* ptr) noexcept;

export void operator delete(void* ptr, size_t size) noexcept;
export void operator delete[](void* ptr, size_t size) noexcept;

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
