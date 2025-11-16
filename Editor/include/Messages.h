/**
 * @file Messages.h
 * @brief It containes the messages to be procesed
 * @date 2025-10-25
 * @version 1.0
 */
#pragma once

#include "std_includes.h"

/// @brief It containes the message to be procesed
class IMessage
{
public:
    enum class Type
    {
        create,
        load_xml,
        load_json,
        save_xml,
        save_json,
        add_primitive,
        del_primitive,
        COUNT
    };

    IMessage()          = default;
    virtual ~IMessage() = default;

    virtual Type get_type() const = 0;
};

class Message : public IMessage
{
public:
    Message(Type type) { m_type = type; }
    Type get_type() const override { return m_type; };

private:
    Type m_type = Type::COUNT;
};
