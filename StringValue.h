#pragma once
#include "Value.h"
#include "String.h"
class StringValue : public Value
{
    void validate();
public:
    StringValue(String);
    String getType() const;
    virtual void save(String);
};