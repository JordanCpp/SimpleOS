
#pragma once

#include <SimpleOS/HAL/IPort.hpp>
#include <SimpleOS/HAL/IKeyboard.hpp>

namespace HAL
{
	class Keyboard : public IKeyboard
	{
	public:
		Keyboard(HAL::IPort* port);
		void Handle();
		int ReadKey();
	private:
		HAL::IPort* _port;
		bool        _release;
		int         _key;
	};
}
