#pragma once
#include "std_includes.h"

class IVewer
{

public:
    IVewer() = default;
    virtual ~IVewer() = default;

    virtual void show(const IDocument &document) const = 0;
};