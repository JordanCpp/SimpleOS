
#pragma once

#include <SimpleOS/Hal/HalConsole.hpp>

namespace HAL
{
	class Console : public IConsole
	{
	public:
		Console();
		~Console();
		void Clear();
		void Write(char c);
		void Write(const char* src);
	};
}
