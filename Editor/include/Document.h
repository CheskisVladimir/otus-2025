#pragma once

#include "std_includes.h"

class IDocument
{
public:
    IDocument(/* args */) = default;
    virtual ~IDocument() = default;
};

class EmptyDocument : public IDocument
{
};