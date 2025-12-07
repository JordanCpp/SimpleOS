
#pragma once

#include <cstdint>
#include <type_traits>

namespace Port
{
    template <typename T>
    inline void Write(uint16_t port, T data)
    {
        static_assert(std::is_same_v<T, uint8_t> ||
            std::is_same_v<T, uint16_t> ||
            std::is_same_v<T, uint32_t>,
            "Unsupported data type. Use uint8_t, uint16_t, uint32_t.");

        if constexpr (std::is_same_v<T, uint8_t>)
        {
            asm volatile("outb %0, %1" : : "a"(data), "dN"(port));
        }
        else if constexpr (std::is_same_v<T, uint16_t>)
        {
            asm volatile("outw %0, %1" : : "a"(data), "dN"(port));
        }
        else if constexpr (std::is_same_v<T, uint32_t>)
        {
            asm volatile("outl %0, %1" : : "a"(data), "dN"(port));
        }
    }

    template <typename T>
    inline T Read(uint16_t port)
    {
        static_assert(std::is_same_v<T, uint8_t> ||
            std::is_same_v<T, uint16_t> ||
            std::is_same_v<T, uint32_t>,
            "Unsupported data type. Use uint8_t, uint16_t, uint32_t.");

        T result;

        if constexpr (std::is_same_v<T, uint8_t>)
        {
            asm volatile("inb %1, %0" : "=a"(result) : "dN"(port));
        }
        else if constexpr (std::is_same_v<T, uint16_t>)
        {
            asm volatile("inw %1, %0" : "=a"(result) : "dN"(port));
        }
        else if constexpr (std::is_same_v<T, uint32_t>)
        {
            asm volatile("inl %1, %0" : "=a"(result) : "dN"(port));
        }

        return result;
    }

    inline void Wait()
    {
        Read<uint16_t>(0x80);
    }
}
