#include "StringValue.h"
StringValue::StringValue(String val) : Value(val)
{
    validate();
}
String StringValue::getType() const
{
    return String("String");
}

void StringValue::save(String val)
{
    this->setValue(val);
}
void StringValue::validate()
{
    
}