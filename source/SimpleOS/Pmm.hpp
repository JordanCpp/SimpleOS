
#pragma once

#include <bitset>
#include <cstddef>
#include <cstring>
#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/Hal/HalPmm.hpp>

namespace HAL
{
	constexpr size_t MapPage   = 4096;
	constexpr size_t TotalBits = (4 * 1024 * 1024) / MapPage;

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
