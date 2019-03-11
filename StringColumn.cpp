#include "StringColumn.h"

StringColumn::StringColumn(String name) : Column(name)
{
}

String StringColumn::getType()
{
    return String("String");
}