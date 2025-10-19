#pragma once

#include "Primitives.h"
#include "std_includes.h"

class EditContext
{
public:
    EditContext() = default;
    const Selection& gt_selection() const;
    Selection& gt_selection();

private:
    Selection m_selection;
};