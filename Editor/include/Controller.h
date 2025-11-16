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

#include "Messages.h"
#include "std_includes.h"

class IContext;
class IDocument;
class IView;
class IAction;
class IActionFactory;

/// @brief It's an interface of Controller in MVC model
class IController : public std::enable_shared_from_this<IController>
{
private:
    /* data */
public:
    IController(/* args */) = default;
    virtual ~IController()  = default;

    virtual const IDocument& get_document() const     = 0;
    virtual bool process_message(const IMessage& msg) = 0;
};

/// @brief IController Implementation
class Controller : public IController
{
public:
    /**
     * Creates document, view and controller\n
     * Calls m_view->set_controller(weak_from_this());
     */
    Controller();

    /**
     * @brief Message processing
     * @code
     * bool process_message(const IMessage& msg) {
     *    auto *action = get_action(msg);
     *    if (action == nullptr){
     *      return false;
     *    }
     *    if (action->execute(msg, *m_context, *m_document))
     *      refresh_view();
     *    return true;
     * }
     * @endcode
     */
    bool process_message(const IMessage& msg) override;

    /// @brief Returns *m_document
    const IDocument& get_document() const override;

    void init_actions(const IActionFactory& factory);

protected:
    /// @brief Finds the action, processed this messages
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
    std::unique_ptr<IContext> m_context;

    std::array<std::unique_ptr<IAction>, size_t(IMessage::Type::COUNT)> m_actions;
};
