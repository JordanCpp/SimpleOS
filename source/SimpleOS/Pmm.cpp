
#include <SimpleOS/Pmm.hpp>

using namespace HAL;

Pmm::Pmm(uintptr_t address) :
	_address(address)
{
	_map.reset();
}

Pmm::~Pmm()
{
}

void* Pmm::Allocate()
{
	size_t index = Find();

	if (index == NotFound)
	{
		return nullptr;
	}

	_map.set(index);

	uintptr_t address = _address + (index * MapPage);

	return reinterpret_cast<void*>(address);
}

void Pmm::Deallocate(void* ptr)
{
	if (ptr)
	{
		uintptr_t address = reinterpret_cast<uintptr_t>(ptr);

		size_t index = (address - _address) / MapPage;

		if (index < TotalBits)
		{
			_map.reset(index);
		}
	}
}

size_t Pmm::Find()
{
	for (size_t i = 0; i < _map.size(); i++)
	{
		if (!_map.test(i))
		{
			return i;
		}
	}

	return NotFound;
}
