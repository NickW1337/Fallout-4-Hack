#pragma once
#include <Windows.h>
#include <iostream>

namespace Cheats {
	class Cheats {
	private:
		HMODULE mod = GetModuleHandleW(NULL);
		uintptr_t baseAddress = reinterpret_cast<uintptr_t>(mod);

	public:
		Cheats();
		~Cheats();

		void InfiniteAmmo();
	};
}

