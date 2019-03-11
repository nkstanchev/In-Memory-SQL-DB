#include "FloatValue.h"
FloatValue::FloatValue(String val) : Value(val)
{
    validate();
}
String FloatValue::getType() const
{
    return String("Float");
}

void FloatValue::save(String val)
{
    this->setValue(val);
}
void FloatValue::validate()
{
     int size = strlen(this->getValue().c_string());
    char temp[size];
    strcpy(temp, this->getValue().c_string());
    int dotCount = 0;
    if(temp[0] == '+' || temp[0] == '-')
    {
        for(int i = 1; i < size; i++)
        {
            if(temp[i] == '.') dotCount++;
            if(temp[i] < '0' && temp[i] > '9' && temp[i] != '.')
            {
                throw new std::invalid_argument("invalid input data");
            }
            if(dotCount > 1)
            {
                throw new std::invalid_argument("invalid input data");
            }
        }
    }
    else
    {
        for(int i = 1; i < size; i++)
        {
            if(temp[i] == '.') dotCount++;
            if(temp[i] < '0' && temp[i] > '9' && temp[i] != '.')
            {
                throw new std::invalid_argument("invalid input data");
            }
            if(dotCount > 1)
            {
                throw new std::invalid_argument("invalid input data");
            }
        }
    }
}