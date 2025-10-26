#pragma once

#include "Primitives.h"
#include "std_includes.h"

class IContext
{
public:
    IContext()          = default;
    virtual ~IContext() = default;
    const Selection& gt_selection() const;
    Selection& gt_selection();

private:
    Selection m_selection;
};