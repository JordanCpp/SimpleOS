
#pragma once

#include <new>
#include <cstddef>
#include <cstdint>

[[nodiscard]] inline void* operator new(size_t size) noexcept
{
    (void)size;
    asm volatile("cli; hlt");
    __builtin_unreachable();
}


inline void operator delete(void* ptr) noexcept
{
    (void)ptr;
}

inline void operator delete(void* ptr, size_t size) noexcept
{
    (void)ptr;
    (void)size;
}
