#pragma once

#include "std_includes.h"

class Selection;
class IPrimitive;

class IDocument
{
public:
    IDocument()                                                                         = default;
    virtual ~IDocument()                                                                = default;
    virtual void add_primitive(const Selection& selection, const IPrimitive& primitive) = 0;
    virtual void delete_primitive(const Selection& selection)                           = 0;
};

class SimpleDocument : public IDocument
{
public:
    SimpleDocument() = default;
    void add_primitive(const Selection&, const IPrimitive&) override {};
    void delete_primitive(const Selection&) override {};
};