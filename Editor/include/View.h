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
    virtual void show(const IDocument&)                        = 0;

    virtual void notify_сontroller(const IMessage& msg) const = 0;
};
