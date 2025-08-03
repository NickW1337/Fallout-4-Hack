#include <Windows.h>
#include <iostream>
#include "IO/IO.h"
#include "Cheats/Cheats.h"

static HMODULE moduleSelf = nullptr;


DWORD WINAPI mainThread() {
    
    IO::IO* io = new IO::IO();
    Cheats::Cheats* cheats = new Cheats::Cheats();



    while (1) {
        if (GetAsyncKeyState(VK_INSERT)) {
            io->~IO();

            FreeLibraryAndExitThread(moduleSelf, 0);
        }
        else if (GetAsyncKeyState(VK_HOME)) {
            cheats->InfiniteAmmo();
        }

        Sleep(100);
    }
    
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  reason,
                       LPVOID lpReserved
                     )
{
    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
        {
            moduleSelf = hModule;

            HANDLE dllThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)mainThread, NULL, NULL, NULL);

            if (dllThread) {
                CloseHandle(dllThread);
            }
            break;
        }
        case DLL_PROCESS_DETACH:
        {
            FreeConsole();
            Beep(300, 300);
            break;
        }
    }
    return TRUE;
}