#include "IntColumn.h"

IntColumn::IntColumn(String name) : Column(name)
{
}

String IntColumn::getType()
{
    return String("Int");
}