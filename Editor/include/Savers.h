#pragma once
#include "std_includes.h"
class IDocument;

class ISaver
{

public:
    ISaver() = default;
    virtual ~ISaver() = default;

    virtual bool save(const IDocument &document) const = 0;
};