/**
 * @file Context.h
 * @brief Current context it includes the selection in the document, primitive to be inserted, etc.
 * @date 2025-10-25
 * @version 1.0
 */
#pragma once

#include "Primitives.h"
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
    CharacterPrimitive() = default;
};

/// @brief Rect, ellipse...
class ShapePrimitive : public IPrimitive
{
public:
    ShapePrimitive() = default;
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