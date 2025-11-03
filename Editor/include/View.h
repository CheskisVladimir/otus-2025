/**
 * @file View.h
 * @brief View in MVC model
 * @date 2025-10-25
 * @version 1.0
 *
 */

#pragma once
#include "std_includes.h"

class IDocument;
class ILoader;
class ISaver;
class IView;
class IAction;
class IMessage;
class IController;
class ISaver;
class ILoader;

/// @brief It's a View in MVC model.
class IView
{
public:
    IView()          = default;
    virtual ~IView() = default;

    /// @brief Sets controller
    virtual void set_controller(std::weak_ptr<IController> controller) = 0;

    /// @brief Shows the Document
    virtual void show(const IDocument&) = 0;

    /// @brief Send user interface messages to the controller
    virtual void notify_сontroller(const IMessage& msg) const = 0;
};

/// @brief It's a View in MVC model.
class View : public IView
{
public:
    View() = default;

    /// @brief Sets controller
    void set_controller(std::weak_ptr<IController>) override;

    /// @brief Shows the Document
    void show(const IDocument&) override;

    /// @brief Sends user interface messages to the controller
    /**
     * @code
     * void notify_сontroller(const IMessage& msg) {
     *    auto controller = m_controller.lock();
     *    if (controller == nullptr){
     *      //DO SOMETHING
     *    }
     *    controller->process_message(msg);
     * }
     * @endcode
     */
    void notify_сontroller(const IMessage& msg) const override;

private:
    std::weak_ptr<IController> m_controller;
};