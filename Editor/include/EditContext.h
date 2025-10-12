#pragma once
#include "std_includes.h"

class EditContext
{
public:
    EditContext() = default;
    size_t selected_primitive_position() const;
};