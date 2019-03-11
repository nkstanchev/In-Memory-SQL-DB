#pragma once
#include "Column.h"
class FloatColumn : public Column
{
public:
    FloatColumn(String name);
    String getType();
};