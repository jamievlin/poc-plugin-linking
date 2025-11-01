#include "LnkInterfaceImpl.h"

#include <iostream>

#if defined(_WIN32)
#define NOMINMAX
#include <Windows.h>
typedef HINSTANCE dynlib_t;
#elif defined(__linux__)
#include <dlfcn.h>
typedef void* dynlib_t;
#endif

typedef void(LNK_CALL* CallFunctionType)(ILnkInterface*);

int main()
{
    LnkInterfaceImpl impl;
    dynlib_t libHandle;
#if defined(_WIN32)
    libHandle = LoadLibrary(TEXT("sub_plugin.dll"));
#elif defined(__linux__)
    libHandle = dlopen("./libsub_plugin.so", RTLD_LAZY);
#endif

    if (libHandle == nullptr)
    {
        std::cerr << "Cannot load library file" << std::endl;
        exit(1);
    }

#if defined(_WIN32)
    auto fnPtr =
        reinterpret_cast<CallFunctionType>(GetProcAddress(libHandle, "pluginCallFunction"));
#elif defined(__linux__)
    auto fnPtr =
        reinterpret_cast<CallFunctionType>(dlsym(libHandle, "pluginCallFunction"));
#endif

    if (fnPtr != nullptr)
    {
        fnPtr(&impl);
    }

#if defined(_WIN32)
    FreeLibrary(libHandle);
#elif defined(__linux__)
    dlclose(libHandle);
#endif

}
