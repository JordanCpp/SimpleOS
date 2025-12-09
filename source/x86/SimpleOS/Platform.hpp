
#pragma once

#include <SimpleOS/Port.hpp>
#include <SimpleOS/Keyboard.hpp>
#include <SimpleOS/PicManager.hpp>
#include <SimpleOS/InterruptManager.hpp>
#include <SimpleOS/InterruptHandlers.hpp>

class Platform
{
public:
	Platform();
	HAL::IKeyboard* GetKeyboard();
private:
	HAL::Port        _port;
	HAL::Keyboard    _keyboard;
	PicManager       _picManager;
	InterruptManager _interruptManager;
};
