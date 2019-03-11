#pragma once
#include "Value.h"
#include "String.h"
class IntValue : public Value
{
    void validate();
public:
    IntValue(String);
    String getType() const;
    virtual void save(String);
    
};