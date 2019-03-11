#pragma once
#include "String.h"
class Value
{
    String val;
    virtual void validate() = 0;
public:
    Value();
    Value(String);
    String getValue() const;
    static Value* factory(String,String);
    void setValue(String);
    virtual void save(String) = 0;
    virtual String getType() const = 0;
    //static Value * factory();
};