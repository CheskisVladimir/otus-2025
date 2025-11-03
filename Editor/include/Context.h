/**
 * @file Context.h
 * @brief Current context it includes the selection in the document, primitive to be inserted, etc.
 * @date 2025-10-25
 * @version 1.0
 */
#pragma once

#include "std_includes.h"

class IPrimitive;
class ISelection;

/// @brief Current context
class IContext
{
public:
    IContext()          = default;
    virtual ~IContext() = default;
    virtual const ISelection& get_selection() const;
    virtual void set_selection(const ISelection&);
    virtual const IPrimitive& get_primitive() const;
    virtual void set_primitive(const IPrimitive&);
};

/// @brief IPrimitive is a part of the document
class IPrimitive
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

/// @brief Selected part of the document
class ISelection
{
public:
    ISelection()          = default;
    virtual ~ISelection() = default;
};

/// @brief Simple selection - start and end of selected part
class SimpleSelection
{
public:
    SimpleSelection() = default;
    std::pair<size_t, size_t> get() const;
    void set(const std::pair<size_t, size_t>&);

private:
    std::pair<size_t, size_t> m_selection;
};