/**
 * @file ActionFactory.h
 * @brief Creates editor actions (save/load, add/remove primitive, etc)
 * @date 2025-10-25
 * @version 1.0
 *
 * @see Messages.h
 * @see Actions.h
 */

#pragma once
#include "Messages.h"
#include "std_includes.h"
class IAction;

/// @brief Action factory interface
class IActionFactory
{
public:
    IActionFactory()          = default;
    virtual ~IActionFactory() = default;

    /// @brief Create action by message type
    virtual std::unique_ptr<IAction> create(IMessage::Type msg_type) const = 0;
};

/// @brief Action factory implementation
class ActionFactory : public IActionFactory
{
public:
    ActionFactory() = default;
    /// @brief Create action by message type
    std::unique_ptr<IAction> create(IMessage::Type msg_type) const override;
};