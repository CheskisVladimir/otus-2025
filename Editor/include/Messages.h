#pragma once
#include "std_includes.h"

class IPrimitive;

class IMessage
{
public:
    IMessage()          = default;
    virtual ~IMessage() = default;
};

class AddPrimitiveMessage
{
public:
    AddPrimitiveMessage();
    const IPrimitive* get_primitive();
};

class RemovePrimitiveMessage
{
public:
    RemovePrimitiveMessage() = default;
};