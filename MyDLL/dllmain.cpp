// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <tchar.h>

// entry point of every dll function
// because there can't be more than one main functions
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // called when libary is loaded with LoadLibrary
        _tprintf(_T("Library loaded\n"));
        break;
    case DLL_THREAD_ATTACH:
        _tprintf(_T("Thread attached\n"));
        break;
    case DLL_THREAD_DETACH:
        _tprintf(_T("Thread detached\n"));
        break;
    case DLL_PROCESS_DETACH:
        // called when libary is freed with FreeLibrary
        _tprintf(_T("Process detached\n"));
        break;
    }
    return TRUE;
}

/*
    Exporting functions
*/
EXTERN_C DWORD AddFunc(DWORD x, DWORD y) {
    return x + y;
}

EXTERN_C DWORD SubFunc(DWORD x, DWORD y) {
    return x - y;
}

EXTERN_C DWORD DivFunc(DWORD x, DWORD y) {
    return x / y;
}

EXTERN_C DWORD ProFunc(DWORD x, DWORD y) {
    return x * y;
}


