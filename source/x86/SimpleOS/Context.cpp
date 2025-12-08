
#include <SimpleOS/Context.hpp>

PicManager*      globalPicManager = nullptr;
HAL::IKeyboard*  globalKeyboard   = nullptr;
HAL::IAllocator* globalAllocator  = nullptr;

HAL::IKeyboard* GetKeyboardHandler()
{
	return globalKeyboard;
}

void SetKeyboardHandler(HAL::IKeyboard* keyboard)
{
	globalKeyboard = keyboard;
}

PicManager* GetPicManagerHandler()
{
	return globalPicManager;
}

void SetPicHandler(PicManager* picManager)
{
	globalPicManager = picManager;
}

HAL::IAllocator* GetAllocatorHandler()
{
	return globalAllocator;
}

void SetAllocatorHandler(HAL::IAllocator* allocator)
{
	globalAllocator = allocator;
}
