#pragma once

#include "std_includes.h"

class IDocument;

class ILoader
{

public:
    ILoader() = default;
    virtual ~ILoader() = default;

    virtual std::unique_ptr<IDocument> load() const = 0;
};