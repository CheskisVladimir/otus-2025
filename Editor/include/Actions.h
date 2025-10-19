#pragma once

#include "std_includes.h"

class EditContext;
class IDocument;
class IMessage;

class Selection;
class Primitive;

/// @brief Interface for all edit document actions (add/remove primitive, etc)
class IAction
{
public:
    IAction()          = default;
    virtual ~IAction() = default;

    /**
        \brief Action implementation

        \param [in] message precessed message
        \param [in, out] context includes current selection, some ather parameters.
        \param [in, out] document edited document


        \return true if something changed, refresh_view required.
    */
    virtual bool perform(const IMessage& message, EditContext& context, IDocument& document) = 0;
};

/// @brief Adds a primitive
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