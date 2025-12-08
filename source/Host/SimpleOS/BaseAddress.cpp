
#include <cstdlib>
#include <SimpleOS/HAL/Config.hpp>
#include <SimpleOS/HAL/BaseAddress.hpp>

uintptr_t HAL::BaseAddress()
{
	uint8_t* ptr = (uint8_t*)malloc(HAL::TotalBytes);

	return reinterpret_cast<uintptr_t>(ptr);
}
