#pragma once
#include <iostream>
#include "Vector.h"
#include "Column.h"
#include "String.h"
#include "Row.h"
class Table 
{
    String name;
    Vector<Column*> columns;
    Vector<Row> rows;
public:
    Table();
    Table(String, Vector<Column*>, Vector<Row>);
    String getName() const;
    void setName(String);
    Vector<Row>& getRows();
    Vector<Column*>& getColumns();
    void listColumns() const;
};