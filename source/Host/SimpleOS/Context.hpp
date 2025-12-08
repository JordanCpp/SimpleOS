
#pragma once

#include <SimpleOS/HAL/IAllocator.hpp>

HAL::IAllocator* GetAllocatorHandler();
void SetAllocatorHandler(HAL::IAllocator* allocator);
