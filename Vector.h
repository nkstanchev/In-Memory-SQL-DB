
#pragma once
#include "stdlib.h"
#include <iostream>
#include <type_traits>
template<typename T>
class Vector
{
    T * arr;
    int size = 0;
    int capacity = 4;
    void copy(const Vector<T>&);
    void delObj();
    void resize();
    int findIndex(T&);
    std::ostream& print(std::ostream& os);
    std::istream& read(std::istream& is, size_t);
public:
    Vector();
    Vector(int);
    Vector(const Vector<T>&);
    Vector<T>& operator = (const Vector<T>&);
    ~Vector();
    int getSize();
    void add(T);
    void del(T&);
    void removeAt(size_t);
    //void print();
    int length() const;
    T& operator [](const int) const;
    friend std::ostream& operator <<(std::ostream& os, Vector<T>& v)
    {
        v.print(os); 
    }
    friend std::istream& operator >>(std::istream& is, Vector<T>& v)
    {
        size_t size;
        is >> size;
        v.read(is, size);
    }
};

template<typename T>
Vector<T>::Vector()
{
    arr = new T[capacity];
}
template<typename T>
Vector<T>::Vector(int capacity)
{
    this->capacity = capacity;
}
template<typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}
template<typename T>
void Vector<T>::delObj()
{
    delete[] this->arr;
}
template<typename T>
void Vector<T>::resize()
{
    capacity *= 2;
    T * tempArr = new T[capacity];
    for(size_t i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    this->copy(other);
}
template<typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& other)
{
    if(this != &other)
    {
        delObj();
        this->copy(other);
    }
    return *this;
}
template<typename T>
Vector<T>::~Vector()
{
    delObj();
}
template<typename T>
int Vector<T>::getSize()
{
    return size;
}
template<typename T>
void Vector<T>::add(T elem)
{
    if(size + 1 == capacity) resize();
    arr[size] = elem;
    size++;
}
template<typename T>
int Vector<T>::findIndex(T& elem)
{
    for (size_t i = 0; i < size; i++) {
        if(arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
template<typename T>
void Vector<T>::del(T& elem)
{
    int index = this->findIndex(elem);
    if(index >= 0)
    {
        T * tempArr = arr;
        
        arr = new T[capacity];
        for (size_t i = 0, j = 0; i < size; i++) {
            if(i != index)
            {
                arr[j++] = tempArr[i];
            }

        }
        size--;
        delete[] tempArr;
    }

}
template<typename T>
std::ostream& Vector<T>::print(std::ostream& os)
{
    for (size_t i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << std::endl;
    return os;
}
template<typename T>
std::istream& Vector<T>::read(std::istream& is, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if(this->size + 1 == this->capacity) resize();
        is >> arr[i];
        this->size++;
    }
    this->size = size;
    this->capacity *= size;
    return is;
}
template<typename T>
T& Vector<T>::operator [](const int index) const
{
    if(index >= 0 && index < size) return arr[index];
}
template<typename T>
int Vector<T>::length() const
{
    return this->size;
}
template<typename T>
void Vector<T>::removeAt(size_t index)
{
    if(index >= 0 && index < size)
    {
        T* temp = new T[capacity];
        size_t j = 0;
        for(size_t i = 0; i < size; i++)
        {
            if(i != index)
            {
                temp[j++] = arr[i];
            }
        }
    
    size--;
    delete[] this->arr;
    this->arr = temp;
    }
}