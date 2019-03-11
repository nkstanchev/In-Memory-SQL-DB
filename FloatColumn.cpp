#include "FloatColumn.h"

FloatColumn::FloatColumn(String name) : Column(name)
{
}


String FloatColumn::getType()
{
    return String("Float");
}