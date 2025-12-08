
#include <SimpleOS/Context.hpp>

extern "C" void InterruptHandler(int number)
{
    GetPicManagerHandler()->Eoi(number);

    switch (number)
    {
    case 0x21:
        if (GetKeyboardHandler())
        {
            GetKeyboardHandler()->Handle();
        }
        break;

    default:
        break;
    }
}
