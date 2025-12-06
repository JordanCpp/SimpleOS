
#pragma once

#include <cstdint>
#include <SimpleOS/HAL/HalPmm.hpp>
#include <SimpleOS/Hal/HalAllocator.hpp>

class BumpAllocator : public HAL::IAllocator
{
public:
	BumpAllocator(HAL::IPmm* pmm);
	~BumpAllocator();
	void* Allocate(size_t size);
	void Deallocate(void* address);
private:
	HAL::IPmm* _pmm;
	uintptr_t  _start;
	uintptr_t  _end;
	uintptr_t  _current;
};
