
module;

#include <cstdint>

export module HAL.BumpAllocator;

import HAL.Config;
import HAL.IAllocator;
import HAL.BaseAddress;
import HAL.IPmm;

export class BumpAllocator : public HAL::IAllocator
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

using namespace HAL;

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
