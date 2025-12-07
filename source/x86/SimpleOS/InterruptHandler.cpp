
#include <SimpleOS/PicManager.hpp>
#include <SimpleOS/Hal/HalKeyboard.hpp>

static PicManager picManager;
HAL::IKeyboard* globalKeyboard = nullptr;

extern "C" void SetKeyboardHandler(HAL::IKeyboard* keyboard) 
{
	globalKeyboard = keyboard;
}

extern "C" void InterruptHandler(int number)
{
    picManager.Eoi(number);

    switch (number)
    {
    case 0x21:
        if (globalKeyboard)
        {
            globalKeyboard->Handle();
        }
        break;

    default:
        break;
    }
}
