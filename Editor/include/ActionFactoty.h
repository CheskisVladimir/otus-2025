#pragma once
#include "Messages.h"
#include "std_includes.h"
class IAction;
class IActionFactory
{
public:
    IActionFactory()          = default;
    virtual ~IActionFactory() = default;

    virtual std::unique_ptr<IAction> create(IMessage::Type msg_type) const = 0;
};

class ActionFactory : public IActionFactory
{
public:
    ActionFactory() = default;
    std::unique_ptr<IAction> create(IMessage::Type msg_type) const override;
};