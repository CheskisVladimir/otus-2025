#pragma once
#include "std_includes.h"

class Primitive;

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
    const Primitive* get_primitive();
};

class RemovePrimitiveMessage
{
public:
    RemovePrimitiveMessage() = default;
};