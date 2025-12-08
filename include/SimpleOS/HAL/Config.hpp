
#pragma once

#include <cstddef>

namespace HAL
{
	constexpr size_t StartAddress = 0x1700000;
	constexpr size_t MapPage      = 4096;
	constexpr size_t TotalMbs     = 4;
	constexpr size_t TotalBytes   = (TotalMbs * 1024 * 1024);
	constexpr size_t TotalBits    = TotalBytes / MapPage;
}
