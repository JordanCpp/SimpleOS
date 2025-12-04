
#pragma once

#include <new>
#include <cstdint>

namespace HAL
{
	class IPmm
	{
	public:
		virtual ~IPmm() = default;
		virtual void* Allocate() = 0;
		virtual void Deallocate(void* address) = 0;
	};
}
