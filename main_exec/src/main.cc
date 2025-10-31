#include "LnkInterfaceImpl.h"

#include <iostream>

#define NOMINMAX
#include <Windows.h>

typedef void(__cdecl* CallFunctionType)(ILnkInterface*);

int main()
{
    LnkInterfaceImpl impl;
    HINSTANCE libHandle = LoadLibrary(TEXT("sub_plugin.dll"));

    if (libHandle == nullptr)
    {
        exit(1);
    }

    auto fnPtr =
        reinterpret_cast<CallFunctionType>(GetProcAddress(libHandle, "pluginCallFunction"));

    if (fnPtr != nullptr)
    {
        fnPtr(&impl);
    }

    FreeLibrary(libHandle);
}
