
#include <cstdlib>
#include <SimpleOS/Hal/HalConfig.hpp>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

uintptr_t HAL::BaseAddress()
{
	uint8_t* ptr = (uint8_t*)malloc(HAL::TotalBytes);

	return reinterpret_cast<uintptr_t>(ptr);
}
