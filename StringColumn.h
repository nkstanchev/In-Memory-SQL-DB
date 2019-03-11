#pragma once
#include "Column.h"
class StringColumn : public Column
{
public:
    StringColumn(String name);
    String getType();
};