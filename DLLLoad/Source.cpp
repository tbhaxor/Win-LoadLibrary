#include <Windows.h>
#include <tchar.h>
#include <libloaderapi.h>
#include <wchar.h>
#include "../MyDLL/Header.h"

int _tmain(DWORD argc, LPTSTR* argv) {
	if (argc < 4) {
		_tprintf(_T("usage: %ws <x> <y> <add|div|prod|sub>\n"), argv[0]);
		return 1;
	}

	DWORD dwX = _wtoi(argv[1]);
	DWORD dwY = _wtoi(argv[2]);

	HMODULE hDll = LoadLibrary(_T("MyDLL"));
	if (!hDll || hDll == INVALID_HANDLE_VALUE) {
		_tprintf(_T("unable to load libraray"));
		return 1;
	}

	_tprintf(_T("library loaded at 0x%x\n"), hDll);
	if (lstrcmp(_T("add"), argv[3]) == 0) {
		AddFunc Add = (AddFunc)GetProcAddress(hDll, "AddFunc");
		if (!Add) _tprintf(_T("unable to load AddFunc\n"));
		else _tprintf(_T("%d + %d = %d\n"), dwX, dwY, Add(dwX, dwY)); 
	}
	else if (lstrcmp(_T("div"), argv[3]) == 0) {
		DivFunc Div = (DivFunc)GetProcAddress(hDll, "DivFunc");
		if (!Div) _tprintf(_T("unable to load DivFunc\n"));
		else _tprintf(_T("%d / %d = %d\n"), dwX, dwY, Div(dwX, dwY));
	}
	else if (lstrcmp(_T("prod"), argv[3]) == 0) {
		ProFunc Pro = (ProFunc)GetProcAddress(hDll, "ProFunc");
		if (!Pro) _tprintf(_T("unable to load DivFunc\n"));
		else _tprintf(_T("%d * %d = %d\n"), dwX, dwY, Pro(dwX, dwY));
	}
	else if (lstrcmp(_T("sub"), argv[3]) == 0) {
		SubFunc Sub = (SubFunc)GetProcAddress(hDll, "ProFunc");
		if (!Sub) _tprintf(_T("unable to load DivFunc\n"));
		else _tprintf(_T("%d - %d = %d\n"), dwX, dwY, Sub(dwX, dwY));
	}
	else {
		_tprintf(_T("invalid operation\n"));
	}

	FreeLibrary(hDll);
}