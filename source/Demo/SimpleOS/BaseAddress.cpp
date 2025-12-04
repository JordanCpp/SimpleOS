
#include <cstdlib>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

uintptr_t HAL::BaseAddress()
{
	uint8_t* ptr = (uint8_t*)malloc(4 * 1024 * 1024);

	return reinterpret_cast<uintptr_t>(ptr);
}
