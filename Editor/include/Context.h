#pragma once

#include "Primitives.h"
#include "std_includes.h"

class IPrimitive;
class ISelection;

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

class IPrimitive
{
public:
    IPrimitive() = default;
    virtual ~IPrimitive() {}
};

class CharPrimitive : public IPrimitive
{
public:
    CharacterPrimitive() = default;
};

class ShapePrimitive : public IPrimitive
{
public:
    ShapePrimitive() = default;
};

class ISelection
{
public:
    ISelection()          = default;
    virtual ~ISelection() = default;
};

class SimpleSelection
{
public:
    SimpleSelection() = default;
    std::pair<size_t, size_t> get() const;
    void set(const std::pair<size_t, size_t>&);

private:
    std::pair<size_t, size_t> m_selection;
};