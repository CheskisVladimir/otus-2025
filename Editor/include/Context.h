/**
 * @file Context.h
 * @brief Current context it includes the selection in the document, primitive to be inserted, etc.
 * @date 2025-10-25
 * @version 1.0
 */
#pragma once

#include "std_includes.h"

class IPrimitive;

/// @brief Current editor context interface
class IContext
{
public:
    /// @brief Selection range structure
    struct selection_t
    {
        size_t start = 0;
        size_t end   = 0;
    };

    IContext()          = default;
    virtual ~IContext() = default;

    /// @brief Set selection range
    virtual void set_selection(const selection_t& selection) = 0;

    /// @brief Get selection range
    virtual selection_t get_selection() const = 0;

    /// @brief Get primitive pointer
    virtual const IPrimitive* get_primitive() const = 0;

    /// @brief Set primitive
    virtual void set(const std::weak_ptr<const IPrimitive>& b) = 0;
};

/// @brief Editor context implementation
class Context : public IContext
{
public:
    Context();
    void set_selection(const selection_t& selection) override;
    selection_t get_selection() const override;
    const IPrimitive* get_primitive() const override;
    void set(const std::weak_ptr<const IPrimitive>& b) override;

private:
    selection_t m_selection;
    std::weak_ptr<const IPrimitive> m_primitive;
};

/// @brief IPrimitive is a part of the document
class IPrimitive : public std::enable_shared_from_this<IPrimitive>
{
public:
    IPrimitive() = default;
    virtual ~IPrimitive() {}
};

/// @brief Simple character
class CharPrimitive : public IPrimitive
{
public:
    CharPrimitive(char ch);
    char get_value() const;

private:
    char m_char;
};

/// @brief Rect, ellipse...
class ShapePrimitive : public IPrimitive
{
public:
    ShapePrimitive(const std::string& shape_type);
    const std::string& get_type() const;

private:
    std::string m_type;
};
