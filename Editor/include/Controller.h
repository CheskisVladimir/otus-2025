/**
 * @file Controller.h
 * @brief It containes the Controller, second class in from MVC model
 * @date 2025-10-25
 * @version 1.0
 *
 * @see Actions.h
 * @see View.h
 * @see Document.h
 * @see Context.h
 */
#pragma once

#include "std_includes.h"

class IContext;
class IDocument;
class IView;
class IAction;
class IMessage;

/// @brief It's an interface of Controller in MVC model
class IController : public std::enable_shared_from_this<IController>
{
private:
    /* data */
public:
    IController(/* args */);
    virtual ~IController() = default;

    virtual const IDocument& get_document() const     = 0;
    virtual void process_message(const IMessage& msg) = 0;
};

/// @brief IController Implementation
class Controller : public IController
{
public:
    Controller();

    /**
     * @brief Message processing
     * @code
     * void process_message(const IMessage& msg) {
     *    auto *action = get_action(msg);
     *    if (action == nullptr){
     *      //DO SOMETHING
     *    }
     *    if (action->execute(msg, *m_context, *m_document))
     *      refresh_view();
     * }
     * @endcode
     */
    virtual void process_message(const IMessage& msg) override;

    /// @brief Returns *m_document
    virtual const IDocument& get_document() const override;

protected:
    virtual IAction* get_action(const IMessage& message) const;

private:
    /// @brief Calls m_view->show(*m_document)
    void refresh_view() const;

    /// @brief Document
    std::unique_ptr<IDocument> m_document;
    /// @brief View
    std::shared_ptr<IView> m_view;

    /// @brief Context
    /// @see Context.h
    std::unique_ptr<EditContext> m_context;
};
