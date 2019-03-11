#include "Table.h"

Table::Table(String name, Vector<Column*> columns, Vector<Row> rows)
{
    this->name = name;
    this->columns = columns;
    this->rows = rows;
}
String Table::getName() const
{
    return name;
}
//fix this method
void Table::listColumns() const
{
    std::cout << "---- Table " << name << " Columns ----" << std::endl;
    size_t length = columns.length();
    if(length == 0)
    {
        std::cout << "Nothing to show" << std::endl;
        return;
    }
    for(size_t i = 0; i < length; i++)
    {
        std::cout << columns[i]->getName() << " : " << columns[i]->getType() << std::endl;
    }
}
Vector<Row>& Table::getRows()
{
    return rows;
}
Vector<Column*>& Table::getColumns()
{
    return columns;
}
void Table::setName(String name)
{
    this->name = name;
}