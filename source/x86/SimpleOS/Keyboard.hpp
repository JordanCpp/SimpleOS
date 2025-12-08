
#pragma once

#include <SimpleOS/HAL/IKeyboard.hpp>

namespace HAL
{
	class Keyboard : public IKeyboard
	{
	public:
		Keyboard();
		void Handle();
		int ReadKey();
	private:
		bool _release;
		int  _key;
	};
}
