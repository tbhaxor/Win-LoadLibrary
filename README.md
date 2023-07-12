# Win LoadLibary

> A simple program to load DLL and call exported functions

I got interested into c++ after watching Pavel sir courses and reading books written by him on system programming. So I decided to explore this on my own and implement DLL rather than using static library

**NOTE:** Although I don't like windows for usage, but I use it for learning exploitation and learning about malwares.

## How DLL is used

1. Create a DLL project (MyDLL)
2. If you want to execute some code on load, use DllMain function already scaffolded, otherwise create functions
3. Load the library using `LoadLibrary` or `LoadLibrayA` function
4. Create cast types for function defined in dllmain.cpp (MyDLL/Header.h)
5. Use the `GetProcAddress` function to find address of the target function from the loaded dll
6. Type cast the `FARPROC` to the typedef from the header file
7. Call the returned function object which has actual reference for executing code
8. Free the library using `FreeLibrary` function

![](https://i.imgur.com/fozF4O6.png)

## Program Usage

Open the code in visual studio and build both the projects for `x86` or `x64` (recommended) architecture and run the program as shown below

```
usage: DLLLoad.exe <x> <y> <add|div|prod|sub>
```

## References

+ https://docs.microsoft.com/en-us/windows/win32/dlls/dllmain
+ https://stackoverflow.com/questions/6945231/int-tmainint-argc-tchar-argv
+ https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress
+ https://docs.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw
+ https://docs.microsoft.com/en-us/cpp/build/exporting-from-a-dll-using-def-files?view=msvc-160
+ https://docs.microsoft.com/en-us/cpp/cpp/extern-cpp?view=msvc-160
+ https://docs.microsoft.com/en-us/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary

## Contact Me

Linkedin: `@tbhaxor` <br>
Twitter: `@tbhaxor` <br>
Email: tbhaxor _dot_ proton _dot_ me
