#include "TableManager.h"
#include <fstream>
#include <cmath>
TableManager::TableManager()
{
    Vector<Table*> tables;
}
Table * TableManager::findByName(String tablename)
{
    size_t length = tables.length();
    
    for(size_t i = 0; i < length; i++)
    {
        if(tables[i]->getName() == tablename)
        {
            return tables[i];
        }
    }
    return nullptr;
}
void TableManager::load(String tablename)
{
  

    std::ifstream file(tablename.c_string());
    String tempTableName;
    file >> tempTableName;
    //check if already exists
    int length = this->tables.length();
    for(size_t i = 0; i < length; i++)
    {
        if(tables[i]->getName() == tablename)
        {
            throw std::invalid_argument("table with this name already exists");
        }
    }
    Vector<Column*> columns;
    String tempName;
    String tempType;
    int columnNumber;
    file >> columnNumber;
    for(size_t i = 0; i < columnNumber; i++)
    {
        file >> tempName;
        file >> tempType;
        columns.add(Column::factory(tempType, tempName));
    }
    
    

    int rowsNumber;
    file >> rowsNumber;
    Vector<Row> rows;
    String tempValue;
    for(size_t i = 0; i < rowsNumber; i++)
    {
        Row tempRow;
        for(size_t j = 0; j < columnNumber; j++)
        {
            file >> tempValue;
            Value * tempVobj = Value::factory(columns[j]->getType(), tempValue);
            tempRow.getValues().add(tempVobj);

        }
        rows.add(tempRow);
    }
    Table * nt = new Table(tempTableName, columns, rows);
    tables.add(nt);
}
void TableManager::showtables()
{
    std::cout << "---- Tables ----" << std::endl;
    size_t length = tables.length();
    if(length == 0)
    {
        std::cout << "---- Nothing to show ----" << std::endl;
        return;
    }
    for(size_t i = 0; i < length; i++)
    {
        std::cout << tables[i]->getName() << std::endl;
    }
}
void TableManager::describe(String tablename)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        tbl->listColumns();
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::print(String tablename)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t length = tbl->getRows().length();
        size_t pages = 1 + ((length - 1) / 5);
        while(true)
        {
            //if(std::cin >> "exit") break;
            if(pages > 1)
            {
                std::cout << "To exit enter -1 " << pages << std::endl;
                std::cout << "Please enter a page number from 1 to " << pages << std::endl;
            }
            else {
                std::cout << "Nothing to show" << pages << std::endl;
                break;
            }
            int pageNum;
            std::cin >> pageNum;
            if (pageNum == -1) break;
            if(pageNum > pages)
            {
                throw std::invalid_argument( "Number not within pages interval" );
            }
            
            for(size_t i = (pageNum - 1) * 5; i < pageNum * 5 && i < length; i++)
            {
                size_t valuesCount = tbl->getRows()[i].getValues().length();
                for(size_t j = 0; j < valuesCount; j++)
                {
                    std::cout << tbl->getRows()[i].getValues()[j]->getValue() << " " ;
                }
                std::cout << endl;
            }
        }
        
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::save(String tablename, String filename)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        std::ofstream file(filename.c_string());
       
        file << tablename;
        file << std::endl;
        size_t columnSize = tbl->getColumns().length();
        file << columnSize; file << std::endl;
        for(size_t i = 0; i < columnSize; i++)
        {
            file << tbl->getColumns()[i]->getName() << " " << tbl->getColumns()[i]->getType() << std::endl;
        }
        size_t rowsSize = tbl->getRows().length();
        if(rowsSize > 0)
        {
            file << rowsSize; file << std::endl;
            for(size_t i = 0; i < rowsSize; i++)
            {
                for(size_t j = 0; j < columnSize; j++)
                {
                    file << tbl->getRows()[i].getValues()[j]->getValue() << " " ;
                }
                file << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::select(size_t columnN, String value, String tablename)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t columnSize = tbl->getColumns().length();
        if(columnN > columnSize)
        {
             throw std::invalid_argument( "Invalid column N" );
        }
        size_t rowsSize = tbl->getRows().length();
        Vector<Row> selectedRows;
        if(rowsSize > 0)
        {
            for(size_t i = 0; i < rowsSize; i++)
            {
                if(tbl->getRows()[i].getValues()[columnN]->getValue() == value)
                {
                    Row selectedRow;
                    for(size_t j = 0; j < columnSize; j++)
                    {
                        Value * tempValue = Value::factory(tbl->getColumns()[columnN]->getType(),tbl->getRows()[i].getValues()[j]->getValue());
                        selectedRow.getValues().add(tempValue);
                    }
                    selectedRows.add(selectedRow);
                }
                
            }
            size_t selectedLength = selectedRows.length();
            size_t pages = 1 + ((selectedLength - 1) / 5);
            while(true)
            {
                //if(std::cin >> "exit") break;
                if(pages > 1)
                {
                    std::cout << "To exit enter -1 " << pages << std::endl;
                    std::cout << "Please enter a page number from 1 to " << pages << std::endl;
                }
                else {
                    std::cout << "Nothing to show" << pages << std::endl;
                    break;
                }
                int pageNum;
                std::cin >> pageNum;
                if (pageNum == -1) break;
                if(pageNum > pages)
                {
                    throw std::invalid_argument( "Number not within pages interval" );
                }
                
                for(size_t i = (pageNum - 1) * 5; i < pageNum * 5 && i < selectedLength; i++)
                {
                    size_t valuesCount = selectedRows[i].getValues().length();
                    for(size_t j = 0; j < valuesCount; j++)
                    {
                        std::cout << selectedRows[i].getValues()[j]->getValue() << " " ;
                    }
                    std::cout << endl;
                }
            }
        }
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::addColumn(String tablename, String columnName, String columnType)
{
    //check if table with this name exists;
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
         //add column to columns
        tbl->getColumns().add(Column::factory(columnType, columnName));

        // add value to each row
        size_t length = tbl->getRows().length();
        for(size_t i = 0; i < length; i++)
        {
            tbl->getRows()[i].getValues().add(Value::factory(columnType, ""));
        }
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
   
    
}
void TableManager::update(String tablename, size_t columnN, String searchValue, size_t targetColumn, String targetValue)
{
    //check if table with this name exists;
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t rowsSize = tbl->getRows().length();
        size_t columnSize = tbl->getColumns().length();
        if(columnSize < columnN || columnSize < targetColumn)
        {
            throw std::invalid_argument( "Invalid column N" );
        }
        for(size_t i = 0; i < rowsSize; i++)
        {
            if(tbl->getRows()[i].getValues()[columnN]->getValue() == searchValue)
            {
                tbl->getRows()[i].getValues()[targetColumn]->save(targetValue);
            }
        }
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::del(String tablename, size_t columnN, String searchValue)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t rowsSize = tbl->getRows().length();
        size_t columnSize = tbl->getColumns().length();
        if(columnSize < columnN)
        {
            throw std::invalid_argument( "Invalid column N" );
        }
        for(size_t i = 0; i < rowsSize; i++)
        {
            if(tbl->getRows()[i].getValues()[columnN]->getValue() == searchValue)
            {
                
                tbl->getRows().removeAt(i);
                break;
            }
        }
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
void TableManager::insert(String tablename, Vector<Column*> columns, Vector<Value*> values)
{
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t valueLength = values.length();
        size_t columnsSize = columns.length();
        if(valueLength != columnsSize || tbl->getColumns().length() != columnsSize) throw std::invalid_argument( "Number of columns does not match number of values" );
        for(size_t i = 0; i < valueLength; i++)
        {
            if(tbl->getColumns()[i]->getType() != columns[i]->getType())
            {
                throw std::invalid_argument( "The type of the columns passed and those of the table do not match" );
            }
        }
        Row newRow;
        for(size_t i = 0; i < valueLength; i++)
        {
            
            if(columns[i]->getType() == values[i]->getType())
            {
                newRow.getValues().add(values[i]);
            }
            else throw std::invalid_argument( "The type of the column and value do not match" );                
            
        }
        tbl->getRows().add(newRow);
    }
    else  std::cout << "No table with this name exists" << std::endl;
}
void TableManager::rename(String tablename, String newName)
{
    Table * tbl = findByName(tablename);
    Table * newtbl = findByName(newName);
    if(tbl != nullptr && newtbl == nullptr)
    {
        tbl->setName(newName);
    }
    else if(tbl != nullptr && newName != nullptr)
    {
        std::cout << "Table with that name already exists" << std::endl;
    }
    else  
    {
        std::cout << "No table with this name exists" << std::endl;
    }
    
}
void TableManager::count(String tablename, size_t columnN, String searchValue)
{
    //check if table with this name exists;
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t rowsSize = tbl->getRows().length();
        size_t columnSize = tbl->getColumns().length();
        size_t rowCount = 0;
        if(columnSize < columnN)
        {
            throw std::invalid_argument( "Invalid column N" );
        }
        for(size_t i = 0; i < rowsSize; i++)
        {
            if(tbl->getRows()[i].getValues()[columnN]->getValue() == searchValue)
            {
                rowCount++;
            }
        }
        std::cout << "Number of rows that contains " << searchValue << " is: " << rowCount << std::endl; 
    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}
int TableManager::innerJoin(String tablename, size_t columnN, String tablename2, size_t targetN)
{
    //check if table with this name exists;
    Table * tbl = findByName(tablename);
    Table * tbl2 = findByName(tablename2);
    if(tbl != nullptr && tbl2 != nullptr)
    {
        Vector<Column*> columns;
        size_t tblColsSize= tbl->getColumns().length();
        size_t tbl2ColsSize = tbl2->getColumns().length();
        size_t tblRowSize = tbl->getRows().length();
        size_t tbl2RowSize = tbl2->getRows().length();
        for(size_t i = 0; i < tblColsSize; i++)
        {
            columns.add(tbl->getColumns()[i]);
        }
        for(size_t i = 0; i < tbl2ColsSize; i++)
        {
            if(i != targetN)
            {
                columns.add(tbl2->getColumns()[i]);
            }
            
        }
        Vector<Row> allRows;

        for(size_t i = 0; i < tblRowSize; i++)
        {
            for(size_t j = 0; j < tbl2RowSize; j++)
            {
                
                Vector<Value*> tempValues;
                if(tbl->getRows()[i].getValues()[columnN]->getValue() == tbl2->getRows()[j].getValues()[targetN]->getValue())
                {
                    for(size_t k = 0; k < tblColsSize; k++)
                    {
                        tempValues.add(tbl->getRows()[i].getValues()[k]);
                    }
                    for(size_t k = 0; k < tbl2ColsSize; k++)
                    {
                        if(k != targetN)
                        {
                            tempValues.add(tbl2->getRows()[j].getValues()[k]);
                        }
                        
                    }
                }
                Row tempRow(tempValues);
                allRows.add(tempRow);
            }
        }
        String joinedName = tablename + String(" ") + tablename2;
        Table * newTable = new Table(joinedName, columns, allRows);
        tables.add(newTable);
        this->print(joinedName);
        return tables.length() - 1;
    }
    else std::cout << "No table with this name exists" << std::endl;
}
void TableManager::aggregate(String tablename, size_t columnN, String searchValue, size_t targetColumn, String operation)
{
    //check if table with this name exists;
    Table * tbl = findByName(tablename);
    if(tbl != nullptr)
    {
        size_t rowsSize = tbl->getRows().length();
        size_t columnSize = tbl->getColumns().length();
        if(columnSize < columnN || columnSize < targetColumn)
        {
            throw std::invalid_argument( "Invalid column N" );
        }
        Vector<float> selectedValues;
        for(size_t i = 0; i < rowsSize; i++)
        {
            if(tbl->getRows()[i].getValues()[columnN]->getValue() == searchValue)
            {
                if(tbl->getRows()[i].getValues()[targetColumn]->getType() != "Int" || tbl->getRows()[i].getValues()[columnN]->getType() != "Float")
                {
                    throw std::invalid_argument( "Row column is not a digit!" );
                }
                //selectedValues.add(tbl->getRows()[i].getValues()[targetColumn]->getValue());
            }
        }

    }
    else
    {
        std::cout << "No table with this name exists" << std::endl;
    }
}