#pragma once
#include "Value.h"
#include "Vector.h"
class Row 
{
    Vector<Value*> values;
public:
    Row();
    Row(Vector<Value*>);
    Vector<Value*>& getValues();
};