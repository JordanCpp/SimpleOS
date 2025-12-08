
#pragma once

#include <SimpleOS/Hal/IKeyboard.hpp>

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
