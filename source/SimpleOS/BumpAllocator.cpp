
#include <SimpleOS/BumpAllocator.hpp>
#include <SimpleOS/Hal/HalBaseAddress.hpp>

BumpAllocator::BumpAllocator(HAL::IPmm* pmm) :
    _pmm(pmm),
    _start(0),
    _end(0),
    _current(0)
{
    _start   = HAL::BaseAddress();
    _end     = _start + HAL::TotalBits * HAL::MapPage;
    _current = _start;
}

BumpAllocator::~BumpAllocator()
{
}

void* BumpAllocator::Allocate(size_t size)
{
    if (size % 8 != 0) 
    {
        size = (size / 8 + 1) * 8;
    }

    if (_current + size > _end) 
    {
        return nullptr;
    }

    void* ptr = (void*)_current;
    _current += size;

    return ptr;
}

void BumpAllocator::Deallocate(void* address)
{
    if (address)
    {
    }
}
