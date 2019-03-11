
#pragma once
#include <iostream>
class StringContainer
{
    char * arr;
    int size = 0;
    int capacity = 4;
    void copy(const StringContainer&);
    void delObj();
    void resize();
    int findIndex(char&);
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is, size_t);
public:
    StringContainer();
    StringContainer(int);
    StringContainer(const StringContainer&);
    StringContainer& operator = (const StringContainer&);
    ~StringContainer();
    int getSize();
    void add(char);
    void del(char);
    //void print();
    int length() const;
    char operator [](const int) const;
    friend std::ostream& operator <<(std::ostream& os, StringContainer& v)
    {
        v.print(os); 
    }
    friend std::istream& operator >>(std::istream& is, StringContainer& v)
    {
        size_t size;
        is >> size;
        v.read(is, size);
    }
};
