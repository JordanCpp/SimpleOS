
module;

export module HAL.Keyboard;

import HAL.IKeyboard;

export namespace HAL
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


using namespace HAL;

Keyboard::Keyboard()
{
}

void Keyboard::Handle()
{
}

int Keyboard::ReadKey()
{
	return 0;
}
