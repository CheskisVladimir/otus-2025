/**
 * @file Messages.h
 * @brief It containes the messages to be procesed
 * @date 2025-10-25
 * @version 1.0
 */

#pragma once

#include "std_includes.h"

/// @brief The message interface
class IMessage
{
public:
    /// @brief Supported message types
    enum class Type
    {
        create,         ///< Create new document
        load_xml,       ///< Load from XML
        load_json,      ///< Load from JSON
        save_xml,       ///< Save to XML
        save_json,      ///< Save to JSON
        add_primitive,  ///< Add primitive
        del_primitive,  ///< Delete primitive
        COUNT           ///< Total count of types
    };

    IMessage()          = default;
    virtual ~IMessage() = default;

    /// @brief Get message type
    virtual Type get_type() const = 0;
};

/// @brief Message to be procesed
class Message : public IMessage
{
public:
    /// @brief Sets message type
    Message(Type type) { m_type = type; }

    /// @brief Get message type
    Type get_type() const override { return m_type; };

private:
    Type m_type = Type::COUNT;
};
