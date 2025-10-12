#pragma once

#include "std_includes.h"

class EditContext;
class IDocument;
class IMessage;

class IAction
{

public:
    IAction() = default;
    virtual ~IAction() = default;

    virtual bool perform(const IMessage &message, EditContext &context, IDocument &document) const = 0;
};