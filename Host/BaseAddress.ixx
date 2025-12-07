
module;

#include <cstdlib>
#include <cstdint>

export module HAL.BaseAddress;

import HAL.Config;

export namespace HAL
{
	uintptr_t BaseAddress();
}

uintptr_t HAL::BaseAddress()
{
	uint8_t* ptr = (uint8_t*)malloc(HAL::TotalBytes);

	return reinterpret_cast<uintptr_t>(ptr);
}