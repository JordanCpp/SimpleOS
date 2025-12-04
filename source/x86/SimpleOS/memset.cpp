
#include <cstdint>
#include <cstddef>

void* memset(void* buf, int c, size_t len)
{
	uint8_t* p = (uint8_t*)buf;

	while (len--)
	{
		*p++ = (uint8_t)c;
	}

	return buf;
}

void* memcpy(void* dest, const void* src, size_t len)
{
	uint8_t* d = (uint8_t*)dest;
	const uint8_t* s = (const uint8_t*)src;

	while (len--)
	{
		*d++ = *s++;
	}

	return dest;
}


void* __memcpy_chk(void* dest, const void* src, size_t len)
{
	return memcpy(dest,src, len);
}

namespace std
{
	void terminate() noexcept
	{
		while (true)
		{
		}
	}
}
