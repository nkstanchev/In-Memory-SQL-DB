#include "Value.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "StringValue.h"
Value::Value()
{
    String val;
}
Value::Value(String _val)
{
    this->val = _val; 
}

String Value::getValue() const
{
    return val;
}
Value* Value::factory(String type, String val)
{
    if(type == "Int") return new IntValue(val);
    else if(type == "Float") return new FloatValue(val);
    else if(type == "String") return new StringValue(val);
}
void Value::setValue(String val)
{
    this->val = val;
}