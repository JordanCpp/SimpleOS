
#include <SimpleOS/HAL/Config.hpp>
#include <SimpleOS/HAL/BaseAddress.hpp>

uintptr_t HAL::BaseAddress()
{
	return StartAddress;
}
