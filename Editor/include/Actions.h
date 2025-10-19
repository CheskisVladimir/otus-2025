#pragma once

#include "std_includes.h"

class EditContext;
class IDocument;
class IMessage;

class Selection;
class Primitive;

/// @brief
class IAction
{
public:
    IAction()          = default;
    virtual ~IAction() = default;

    virtual bool perform(const IMessage& message, EditContext& context, IDocument& document) = 0;
};

class AddPrimitiveAction : public IAction
{
public:
    AddPrimitiveAction() = default;

    bool perform(const IMessage& message, EditContext& context, IDocument& document) override;

private:
    bool get_parameters(const IMessage& message,
                        EditContext& context,
                        const IPrimitive& primitive,
                        const Selection& selection) const;
};

class RemovePrimitiveAction : public IAction
{
public:
    RemovePrimitiveAction() = default;

    bool perform(const IMessage& message, EditContext& context, IDocument& document) override;

private:
    bool get_parameters(const IMessage& message,
                        EditContext& context,
                        const Selection& selection) const;
};