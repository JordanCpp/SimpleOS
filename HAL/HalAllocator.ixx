
module;

#include <cstddef>

export module HAL.IAllocator;

export namespace HAL
{
	class IAllocator
	{
	public:
		virtual ~IAllocator() = default;
		virtual void* Allocate(size_t size) = 0;
		virtual void Deallocate(void* address) = 0;
	};
}