
#include <SimpleOS/Context.hpp>
#include <SimpleOS/Platform.hpp>
#include <SimpleOS/Interrupt.hpp>

Platform::Platform() :
    _keyboard(&_port),
    _picManager(&_port)
{
    GetContext().SetPicHandler(&_picManager);

    _picManager.Remap(0x20, 0x28);

    GetContext().SetKeyboardHandler(&_keyboard);

    _interruptManager.Set(Interrupt::Timer, (void*)isr32);
    _interruptManager.Set(Interrupt::Keyboard, (void*)isr33);
    _interruptManager.Load();
    _interruptManager.Enable();

    //_picManager.Unmask(0);
    _picManager.Unmask(1);
}

HAL::IKeyboard* Platform::GetKeyboard()
{
    return &_keyboard;
}
