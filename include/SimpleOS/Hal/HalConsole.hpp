
#pragma once

#include <new>
#include <cstdint>

namespace HAL
{
	class IConsole
	{
	public:
		virtual ~IConsole() = default;
		virtual void Clear() = 0;
		virtual void Write(char c) = 0;
		virtual void Write(const char* src) = 0;
	};
}
