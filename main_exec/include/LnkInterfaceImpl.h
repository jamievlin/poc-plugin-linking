#pragma once

#include "lnk_interface.h"

class LnkInterfaceImpl : public ILnkInterface
{
public:
    int getValue() override;
};
