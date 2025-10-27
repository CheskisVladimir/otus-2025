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

    void set_controller(std::weak_ptr<IController> controller) = 0;

    /// @brief Shows the Document
    virtual void show(const IDocument&) = 0;

    /// @brief Send user interface messages to the controller
    virtual void notify_сontroller(const IMessage& msg) const = 0;
};
