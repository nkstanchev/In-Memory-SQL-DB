#pragma once
#include <iostream>
#include "String.h"
class Column
{
    String name;
public:
    Column();
    Column(String);
    String getName() const;
    void setName(String);
    virtual String getType() = 0;
    static Column* factory(String,String);
};