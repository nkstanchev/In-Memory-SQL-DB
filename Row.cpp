#include "Row.h"

Row::Row()
{
    Vector<Value*> values;
}
Row::Row(Vector<Value*> values)
{
    this->values = values;
}
Vector<Value*>& Row::getValues()
{
    return values;
}