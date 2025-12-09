
#if defined(WIN32)
    #include <conio.h>
#endif

#include <SimpleOS/Keyboard.hpp>

using namespace HAL;

Keyboard::Keyboard()
{
}

void Keyboard::Handle()
{
}

int Keyboard::ReadKey()
{
	int ch = 0;

#if defined(WIN32)
	if (kbhit())
	{
		ch = getch();
	}
#endif

	return ch;
}
