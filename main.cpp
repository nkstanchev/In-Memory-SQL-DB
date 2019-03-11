#include <iostream>
#include "TableManager.h"
#include "IntColumn.h"
#include "StringColumn.h"
#include "FloatColumn.h"
#include "IntValue.h"
#include "FloatValue.h"
#include "StringValue.h"
int main()
{
    //vsichki zakomentirani sam gi testval i mislq che rabotqt
    // prosto sym gi zakomentiral za da e po lesno testvaneto
    TableManager tm;
    String s1("users.txt");
    String s2("countries.txt");
    tm.load(s1) ;
    tm.showtables();
    tm.describe(String("Users"));
    //tm.describe(String("Users2"));
    //tm.update(String("Users"), 0, String("1"), 1 ,String("Gosho"));
    //tm.select(1, String("Pesho"), String("Users"));
    //tm.del(String("Users"), 0, String("1"));
    //tm.print(String("Users"));
    //tm.save(String("Users"), String("files/tezt.txt"));
    //tm.addColumn("Users", "Favourite number", "Int");
    
    // Vector<Column*> columns;
    // Column * col1 = new IntColumn("id");
    // columns.add(col1);
    // Column * col2 = new StringColumn("name");
    // columns.add(col2);
    // Column * col3 = new IntColumn("age");
    // columns.add(col3);
    // Column * col4 = new FloatColumn("points");
    // columns.add(col4);
    // Column * col5 = new StringColumn("city");
    // columns.add(col5);

    // Vector<Value*> values;
    // Value * val1 = new IntValue("13");
    // values.add(val1);
    // Value * val2 = new StringValue("Pesho13");
    // values.add(val2);
    // Value * val3 = new IntValue("58");
    // values.add(val3);
    // Value * val4 = new FloatValue("0.00");
    // values.add(val4);
    // Value * val5 = new StringValue("Montana");
    // values.add(val5);
    // tm.insert(String("Users"), columns, values);
    
    
    // tm.print(String("Users"));

    //tm.rename(String("Users"), String("Users2"));

    tm.count(String("Users"), 1, String("Pesho"));
    tm.describe(String("Users"));
    tm.load(s2);
    tm.innerJoin(String("Users"),4, String("countries"), 0);
    return 0;
}