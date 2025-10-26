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
    virtual bool execute(const IMessage& message, EditContext& context, IDocument& document) = 0;
};

class ILoadAction : public IAction
{
};
class ISaveAction : public IAction
{
};
class IEditAction : public IAction
{
};

class SaveXMLAction : public ISaveAction
{
};
class SaveJsonAction : public ISaveAction
{
};

class LoadXMLAction : public ILoadAction
{
};
class LoadJsonAction : public ILoadAction
{
};

class AddPrimitiveAction : IEditAction
{
};

class DelPrimitiveAction : public IEditAction
{
};
