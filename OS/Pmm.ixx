
module;

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <limits>

export module HAL.Pmm;

import HAL.Config;
import HAL.IPmm;

export namespace HAL
{
	class Pmm : public IPmm
	{
	public:
		const size_t NotFound = std::numeric_limits<size_t>().max();
		Pmm(uintptr_t address);
		~Pmm();
		void* Allocate();
		void Deallocate(void* address);
	private:
		size_t Find();
		uintptr_t              _address;
		std::bitset<TotalBits> _map;
	};
}

namespace HAL
{
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
}