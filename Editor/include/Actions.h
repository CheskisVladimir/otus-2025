/**
 * @file Actions.h
 * @brief Edit document actions (save/load, add/remove primitive, etc)
 * @date 2025-10-25
 * @version 1.0
 *
 * @see Messages.h
 * @see View.h
 * @see Document.h
 * @see Context.h
 */

#pragma once

#include "std_includes.h"

class EditContext;
class IDocument;
class IMessage;

class Selection;
class Primitive;

/// @brief Interface for all edit document actions (save/load, add/remove primitive, etc)
class IAction
{
public:
    IAction()          = default;
    virtual ~IAction() = default;

    /**
        \brief Action implementation

        \param [in] message precessed message
        \param [in, out] context includes current selection, some ather parameters. The action can
       change it.
        \param [in, out] document edited document


        \return true if something changed, refresh_view required.
    */
    virtual bool execute(const IMessage& message, EditContext& context, IDocument& document) = 0;
};

/// @brief Base class for the loading actions
class ILoadAction : public IAction
{
};

/// @brief Base class for the save document actions
class ISaveAction : public IAction
{
};

/// @brief Base class for the edit document actions
class IEditAction : public IAction
{
};

/// @brief Saves a document to the XML file
class SaveXMLAction : public ISaveAction
{
};

/// @brief Saves a document to the json file
class SaveJsonAction : public ISaveAction
{
};

/// @brief Loads a document from the XML file
class LoadXMLAction : public ILoadAction
{
};

/// @brief Loads a document from the json file
class LoadJsonAction : public ILoadAction
{
};

/// @brief Takes from IContext current ISelection and IPrimitive, adds the primitive at the selected
/// position
class AddPrimitiveAction : IEditAction
{
};

/// @brief Takes from IContext current ISelection , removes the primitive at the selected position
class DelPrimitiveAction : public IEditAction
{
};
