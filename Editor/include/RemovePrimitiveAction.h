#pragma once

#include "IAction.h"

class RemovePrimitiveAction : public IAction
{

public:
    RemovePrimitiveAction() = default;
    bool perform(const IMessage &message, EditContext &context1, IDocument &document) const override;
};