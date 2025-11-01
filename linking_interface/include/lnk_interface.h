#pragma once

class ILnkInterface
{
public:
    virtual ~ILnkInterface() = default;

    virtual int getValue() = 0;
};

#if defined(_WIN32)
#define LNK_DYN_EXPORT __declspec(dllexport)

#ifndef _M_X64
#define LNK_CALL __cdecl
#else
#define LNK_CALL
#endif

#elif defined(__linux__)
#define LNK_DYN_EXPORT [[gnu::visibility("default")]]

#ifndef __LP64__
#define LNK_CALL __attribute__((__cdecl__))
#else
#define LNK_CALL
#endif

#elif defined(__APPLE__)
#error Unfortuantely, I do not know how to implement dynamic object linking in apple \
    and I do not have a mac to test on
#else
#error "For now, dynamic object linking is only supported on linux and windows :("
#endif
