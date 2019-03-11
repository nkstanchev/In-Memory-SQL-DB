#include "Column.h"
#include "IntColumn.h"
#include "FloatColumn.h"
#include "StringColumn.h"

Column::Column()
{
    //this->name = name;
}

Column::Column(String name)
{
    this->name = name;
}
String Column::getName() const
{
    return this->name;
}
void Column::setName(String name)
{
    this->name = name;
}
Column* Column::factory(String type, String name)
{
    if(type == "Int") return new IntColumn(name);
    else if(type == "Float") return new FloatColumn(name);
    else if(type == "String") return new StringColumn(name);
}