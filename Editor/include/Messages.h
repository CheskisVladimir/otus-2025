#pragma once

#include "std_includes.h"

/// @brief It containes the command to be procesed
class IMessage
{
public:
    IMessage()          = default;
    virtual ~IMessage() = default;
};
