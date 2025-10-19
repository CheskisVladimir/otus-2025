#pragma once
#include "std_includes.h"

/// @brief
class Selection
{
public:
    Selection() = default;
    Selection(size_t start, size_t end);

    size_t get_start() const;
    size_t get_end() const;
    void set_start(size_t start) const;
    void set_end(size_t end) const;

private:
    size_t m_start = 0;
    size_t m_end   = 0;
};

class IPrimitive
{
public:
    IPrimitive() = default;
    virtual ~IPrimitive() {}
};

class IPrimitive
{
public:
    IPrimitive() = default;
    virtual ~IPrimitive() {}
};

class CharacterPrimitive : public IPrimitive
{
public:
    CharacterPrimitive() = default;
};

class ShapePrimitive : public IPrimitive
{
public:
    ShapePrimitive() = default;
};