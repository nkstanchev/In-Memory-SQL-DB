#pragma once
#include <iostream>
#include "Table.h"
#include "Vector.h"
#include "String.h"
class TableManager
{
    Vector<Table*> tables;
    Table * findByName(String);
public:
    TableManager();
    void load(String);
    void showtables();
    void describe(String);
    void print(String);
    void save(String, String);
    void select(size_t, String, String);
    void addColumn(String, String, String);
    void update(String, size_t, String, size_t, String);
    void del(String, size_t, String);
    void insert(String, Vector<Column*>, Vector<Value*>);
    void rename(String, String);
    void count(String, size_t, String);
    int innerJoin(String, size_t, String, size_t);
    void aggregate(String, size_t, String, size_t,String);
};