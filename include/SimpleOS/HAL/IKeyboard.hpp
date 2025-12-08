
#pragma once

#include <cstdint>

namespace HAL
{
	class IKeyboard
	{
	public:
		virtual ~IKeyboard() = default;
		virtual void Handle() = 0;
		virtual int ReadKey() = 0;
	};
}
