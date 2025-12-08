
#include <SimpleOS/Platform.hpp>

Platform::Platform()
{
}

HAL::IKeyboard* Platform::GetKeyboard()
{
    return &_keyboard;
}
