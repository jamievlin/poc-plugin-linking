#pragma once

#include "lnk_interface.h"

extern "C"
{
    __declspec(dllexport)
    void __cdecl pluginCallFunction(ILnkInterface* interface);
}
