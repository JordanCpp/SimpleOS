
module;

export module HAL.Platform;

import HAL.IKeyboard;
import HAL.Keyboard;

export class Platform
{
public:
	Platform();
	HAL::IKeyboard* GetKeyboard();
private:
	HAL::Keyboard _keyboard;
};

using namespace HAL;

Platform::Platform()
{
}

IKeyboard* Platform::GetKeyboard()
{
    return &_keyboard;
}