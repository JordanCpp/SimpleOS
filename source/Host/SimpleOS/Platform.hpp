
#pragma once

#include <SimpleOS/Keyboard.hpp>

class Platform
{
public:
	Platform();
	HAL::IKeyboard* Platform::GetKeyboard();
private:
	HAL::Keyboard _keyboard;
};
