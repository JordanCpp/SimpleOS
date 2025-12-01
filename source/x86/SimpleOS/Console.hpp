
#pragma once

#include <SimpleOS/ExtNew.hpp>
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
	private:
		void Write(char c, uint8_t x, uint8_t y);
		uint8_t   _cursorX;
		uint8_t   _cursorY;
		uint16_t* _buffer;
	};
}
