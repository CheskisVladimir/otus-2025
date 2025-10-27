/**
 * @file Messages.h
 * @brief It containes the messages to be procesed
 * @date 2025-10-25
 * @version 1.0
 */
#pragma once

#include "std_includes.h"

/// @brief It containes the message to be procesed
class IMessage
{
public:
    IMessage()          = default;
    virtual ~IMessage() = default;
};
