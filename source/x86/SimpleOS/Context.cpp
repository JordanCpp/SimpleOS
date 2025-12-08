
#include <SimpleOS/Context.hpp>

Context::Context() :
	_picManager(nullptr),
	_keyboard(nullptr),
	_allocator(nullptr)
{
}

HAL::IKeyboard* Context::GetKeyboardHandler()
{
	return _keyboard;
}

void Context::SetKeyboardHandler(HAL::IKeyboard* keyboard)
{
	_keyboard = keyboard;
}

PicManager* Context::GetPicManagerHandler()
{
	return _picManager;
}

void Context::SetPicHandler(PicManager* picManager)
{
	_picManager = picManager;
}

HAL::IAllocator* Context::GetAllocatorHandler()
{
	return _allocator;
}

void Context::SetAllocatorHandler(HAL::IAllocator* allocator)
{
	_allocator = allocator;
}

Context globalContext;

Context& GetContext()
{
	return globalContext;
}