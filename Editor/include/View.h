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

class IView
{
public:
    IView()          = default;
    virtual ~IView() = default;

    void set_controller(std::weak_ptr<IController> controller);
    virtual void show() const = 0;

    virtual void notify_сontroller(const IMessage& msg) const           = 0;
    virtual void notify_сontroller_saving(const ISaver& saver) const    = 0;
    virtual void notify_сontroller_loading(const ILoader& loader) const = 0;
};
