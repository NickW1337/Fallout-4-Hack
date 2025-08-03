#include "Cheats.h"


namespace Cheats {
	Cheats::Cheats() {

	}

	Cheats::~Cheats() {

	}

	void Cheats::InfiniteAmmo() {
        uintptr_t ammoInstruction = baseAddress + 0xCABF35;

        unsigned char* bytes = (unsigned char*)ammoInstruction;

        DWORD oldProtect;
        VirtualProtect((void*)ammoInstruction, 8, PAGE_EXECUTE_READWRITE, &oldProtect);
        bytes[0] = 0xC7;
        bytes[1] = 0x41;
        bytes[2] = 0x18;
        bytes[3] = 0xE8;
        bytes[4] = 0x03;
        bytes[5] = 0x00;
        bytes[6] = 0x00;
        bytes[7] = 0x90;
        VirtualProtect((void*)ammoInstruction, 8, oldProtect, &oldProtect);
	}
}