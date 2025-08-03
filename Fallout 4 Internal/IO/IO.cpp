#include "IO.h"

namespace IO {
	IO::IO() {
        Beep(300, 200);
        this->spawnConsole();
	}

    IO::~IO() {
        SetConsoleTitleA("[DETACHED] Fallout 4 Hack");
        FreeConsole();
    }

    void IO::spawnConsole() {
        if (AllocConsole())
        {
            FILE* fp;
            freopen_s(&fp, "CONOUT$", "w", stdout);
            freopen_s(&fp, "CONOUT$", "w", stderr);
            freopen_s(&fp, "CONIN$", "r", stdin);

            std::ios::sync_with_stdio();

            SetConsoleTitleA("Fallout 4 Hack");
        }
        else
        {
            DWORD err = GetLastError();
            OutputDebugStringA("Spawning Console Failed.\n");
        }
    }
}