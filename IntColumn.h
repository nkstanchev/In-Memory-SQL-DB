#pragma once
#include "Column.h"
class IntColumn : public Column
{
public:
    IntColumn(String);
    String getType();
};