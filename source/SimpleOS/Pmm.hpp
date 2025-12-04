
#pragma once

#include <bitset>
#include <cstddef>
#include <cstring>
#include <cstdint>
#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/Hal/HalPmm.hpp>

namespace HAL
{
	class Pmm : public IPmm
	{
	public:
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
