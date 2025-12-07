
#include <SimpleOS/Port.hpp>
#include <SimpleOS/Keyboard.hpp>

using namespace HAL;

Keyboard::Keyboard() :
	_release(false),
	_key(0)
{
}

void Keyboard::Handle()
{
	_key = Port::Read<uint8_t>(static_cast<uint8_t>(0x60));
}

int Keyboard::ReadKey()
{
	if (_key != 0)
	{
		int result = _key;
		_key = 0;

		return result;
	}

	return 0;
}
