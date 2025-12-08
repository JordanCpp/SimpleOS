
#pragma once

#include <SimpleOS/ExtNew.hpp>
#include <SimpleOS/HAL/IConsole.hpp>

namespace HAL
{
	class Console : public IConsole
	{
	public:
		enum
		{
			Address = 0xB8000,
			Width   = 80,
			Heigth  = 25
		};
		Console();
		~Console();
		void Clear() noexcept;
		void Write(char c) noexcept;
		void Write(const char* src) noexcept;
	private:
		void Write(char c, uint8_t x, uint8_t y) noexcept;
		uint8_t   _cursorX;
		uint8_t   _cursorY;
		uint16_t* _buffer;
	};
}
