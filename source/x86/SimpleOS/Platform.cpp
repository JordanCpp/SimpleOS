
#include <SimpleOS/Platform.hpp>

extern "C" void SetKeyboardHandler(HAL::IKeyboard* keyboard);

Platform::Platform()
{
    _picManager.Remap(0x20, 0x28);

    SetKeyboardHandler(&_keyboard);

    _interruptManager.Set(0x20, (void*)isr32);
    _interruptManager.Set(0x21, (void*)isr33);
    _interruptManager.Load();
    _interruptManager.Enable();

    _picManager.Unmask(1);
}

HAL::IKeyboard* Platform::GetKeyboard()
{
    return &_keyboard;
}
