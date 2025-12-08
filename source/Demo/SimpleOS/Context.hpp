
#pragma once

#include <SimpleOS/HAL/HalAllocator.hpp>

HAL::IAllocator* GetAllocatorHandler();
void SetAllocatorHandler(HAL::IAllocator* allocator);
