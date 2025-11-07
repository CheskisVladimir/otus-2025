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

class IContext;
class IDocument;
class IMessage;

class ISelection;
class IPrimitive;

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
    virtual bool execute(const IMessage& message, IContext& context, IDocument& document) = 0;
};

/// @brief Creates new document
class CreateDocumentAction : public IAction
{
public:
    CreateDocumentAction() = default;
    /// @brief Creates new document
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Base class for the loading actions
class ILoadAction : public IAction
{
public:
    ILoadAction() = default;
};

/// @brief Base class for the save document actions
class ISaveAction : public IAction
{
public:
    ISaveAction() = default;
};

/// @brief Base class for the edit document actions
class IEditAction : public IAction
{
public:
    IEditAction() = default;
};

/// @brief Saves a document to the XML file
class SaveXMLAction : public ISaveAction
{
public:
    SaveXMLAction() = default;
    /// @brief Saves a document to the XML file
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Saves a document to the json file
class SaveJsonAction : public ISaveAction
{
public:
    SaveJsonAction() = default;
    /// @brief Saves a document to the json file
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Loads a document from the XML file
class LoadXMLAction : public ILoadAction
{
public:
    LoadXMLAction() = default;
    /// @brief Loads a document from the XML file
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Loads a document from the json file
class LoadJsonAction : public ILoadAction
{
public:
    LoadJsonAction() = default;
    /// @brief Loads a document from the json file
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Takes from IContext current ISelection and IPrimitive, adds the primitive at the selected
/// position
class AddPrimitiveAction : IEditAction
{
public:
    AddPrimitiveAction() = default;
    /// @brief Adds primitive
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};

/// @brief Takes from IContext current ISelection , removes the primitive at the selected position
class DelPrimitiveAction : public IEditAction
{
public:
    DelPrimitiveAction() = default;
    /// @brief Deletes primitive
    bool execute(const IMessage& message, IContext& context, IDocument& document) override;
};
