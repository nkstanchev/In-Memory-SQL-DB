#pragma once
#include "Value.h"
#include "String.h"
class FloatValue : public Value
{
    void validate();
public:
    FloatValue(String);
    String getType() const;
    virtual void save(String);
};