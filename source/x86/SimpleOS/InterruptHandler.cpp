
#include <SimpleOS/Context.hpp>

extern "C" void InterruptHandler(int number)
{
    GetContext().GetPicManagerHandler()->Eoi(number);

    switch (number)
    {
    case 0x21:
        if (GetContext().GetKeyboardHandler())
        {
            GetContext().GetKeyboardHandler()->Handle();
        }
        break;

    default:
        break;
    }
}
