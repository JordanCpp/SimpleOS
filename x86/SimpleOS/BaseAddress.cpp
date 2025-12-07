
#include <SimpleOS/Hal/HalConfig.hpp>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

uintptr_t HAL::BaseAddress()
{
	return StartAddress;
}
