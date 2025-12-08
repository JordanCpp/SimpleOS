
#pragma once

#include <SimpleOS/HAL/IAllocator.hpp>

class Context
{
public:
	Context();
	HAL::IAllocator* GetAllocatorHandler();
	void SetAllocatorHandler(HAL::IAllocator* allocator);
private:
	HAL::IAllocator* _allocator;
};

Context& GetContext();
