
#pragma once

#include <cstdint>

namespace HAL
{
	class IPort
	{
	public:
		virtual ~IPort() = default;
		virtual void Write(uint16_t port, uint8_t data) = 0;
		virtual void Write(uint16_t port, uint16_t data) = 0;
		virtual void Write(uint16_t port, uint32_t data) = 0;
		virtual uint8_t Read8(uint16_t port) = 0;
		virtual uint16_t Read16(uint16_t port) = 0;
		virtual uint32_t Read32(uint16_t port) = 0;
		virtual void Wait() = 0;
	};
}
