
#pragma once

#include <SimpleOS/Hal/HalKeyboard.hpp>

namespace HAL
{
	class Keyboard : public IKeyboard
	{
	public:
		Keyboard();
		void Handle();
		int ReadKey();
	private:
	};
}
