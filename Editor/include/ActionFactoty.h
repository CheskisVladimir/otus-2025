/// \file ActionFactoty.h
/// \brief Creates editor actions (save/load, add/remove primitive, etc)

#pragma once
#include "Messages.h"
#include "std_includes.h"
class IAction;

/// @brief Action factory interface
/// @brief Creates editor actions (save/load, add/remove primitive, etc)
class IActionFactory
{
public:
    IActionFactory()          = default;
    virtual ~IActionFactory() = default;

    /// @brief Create action by message type
    virtual std::unique_ptr<IAction> create(MessageType msg_type) const = 0;
};

/// @brief Creates editor actions (save/load, add/remove primitive, etc)
class ActionFactory : public IActionFactory
{
public:
    ActionFactory() = default;
    /// @brief Create action by message type
    std::unique_ptr<IAction> create(MessageType msg_type) const override;
};