
#pragma once

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <SimpleOS/HAL/IPmm.hpp>

namespace HAL
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
