
#pragma once

#include <cstddef>

namespace HAL
{
	class IAllocator
	{
	public:
		virtual ~IAllocator() = default;
		virtual void* Allocate(size_t size) = 0;
		virtual void Deallocate(void* address) = 0;
	};
}
