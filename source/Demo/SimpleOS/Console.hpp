
#pragma once

#include <SimpleOS/Hal/HalConsole.hpp>

namespace HAL
{
	class Console : public IConsole
	{
	public:
		Console();
		~Console();
		void Clear() noexcept;
		void Write(char c) noexcept;
		void Write(const char* src) noexcept;
	};
}
