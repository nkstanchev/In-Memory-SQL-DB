#include "IntValue.h"
#include <cstring>
IntValue::IntValue(String val) : Value(val)
{
    validate();
}
String IntValue::getType() const
{
    return String("Int");
}

void IntValue::save(String val)
{
    this->setValue(val);
}
void IntValue::validate()
{
    int size = strlen(this->getValue().c_string());
    char temp[size];
    strcpy(temp, this->getValue().c_string());
    if(temp[0] == '+' || temp[0] == '-')
    {
        for(int i = 1; i < size; i++)
        {
            if(temp[i] < '0' && temp[i] > '9')
            {
                throw new std::invalid_argument("invalid input data");
            }
        }
    }
    else
    {
        for(int i = 1; i < size; i++)
        {
            if(temp[i] < '0' && temp[i] > '9')
            {
                throw new std::invalid_argument("invalid input data");
            }
        }
    }
    
}