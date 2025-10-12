#pragma once

#include "IAction.h"

class AddPrimitiveAction : public IAction
{

public:
    AddPrimitiveAction() = default;

    bool perform(const IMessage &message, EditContext &context1, IDocument &document) const override;
};
