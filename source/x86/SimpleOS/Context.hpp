
#pragma once

#include <SimpleOS/PicManager.hpp>
#include <SimpleOS/Hal/HalKeyboard.hpp>
#include <SimpleOS/HAL/HalAllocator.hpp>

HAL::IKeyboard* GetKeyboardHandler();
void SetKeyboardHandler(HAL::IKeyboard* keyboard);

PicManager* GetPicManagerHandler();
void SetPicHandler(PicManager* picManager);

HAL::IAllocator* GetAllocatorHandler();
void SetAllocatorHandler(HAL::IAllocator* allocator);
