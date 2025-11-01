#pragma once

#include "lnk_interface.h"

class LnkInterfaceImpl : public ILnkInterface
{
public:
    LnkInterfaceImpl() = default;
    ~LnkInterfaceImpl() override = default;
    LnkInterfaceImpl(LnkInterfaceImpl& other) = default;
    LnkInterfaceImpl& operator=(LnkInterfaceImpl const& other) = default;

    LnkInterfaceImpl(LnkInterfaceImpl&& other) = default;
    LnkInterfaceImpl& operator=(LnkInterfaceImpl&& other) = default;

    int getValue() override;
};
