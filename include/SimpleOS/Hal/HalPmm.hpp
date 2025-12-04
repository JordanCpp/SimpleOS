
#pragma once

#include <SimpleOS/Hal/HalConfig.hpp>

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
