
#pragma once

#include <array>
#include <cstddef>
#include <SimpleOS/Interrupt.hpp>

class InterruptManager
{
public:
	enum
	{
		IdtMax = 256
	};
	InterruptManager();
	void Load();
	void Enable();
	void Set(uint8_t num, void* handler);
private:
	InterruptRegister              _register;
	std::array<Interrupt, IdtMax>  _table;
};
