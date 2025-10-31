#pragma once

class ILnkInterface
{
public:
    virtual ~ILnkInterface() = default;

    virtual int getValue() = 0;
};
