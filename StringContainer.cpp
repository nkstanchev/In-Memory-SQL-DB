#include "StringContainer.h"

StringContainer::StringContainer()
{
    arr = new char[capacity];
}
StringContainer::StringContainer(int capacity)
{
    this->capacity = capacity;
}
void StringContainer::copy(const StringContainer& other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->arr = new char[capacity];
    for (size_t i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}
void StringContainer::delObj()
{
    delete[] this->arr;
}
void StringContainer::resize()
{
    capacity += 1;
    char * tempArr = new char[capacity];
    for(size_t i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;
}
StringContainer::StringContainer(const StringContainer& other)
{
    this->copy(other);
}
StringContainer& StringContainer::operator = (const StringContainer& other)
{
    if(this != &other)
    {
        delObj();
        this->copy(other);
    }
}
StringContainer::~StringContainer()
{
    delObj();
}
int StringContainer::getSize()
{
    return size;
}
void StringContainer::add(char elem)
{
    if(size + 1 == capacity) resize();
    arr[size] = elem;
    arr[size + 1] = '\0';
    size++;
}
int StringContainer::findIndex(char& elem)
{
    for (size_t i = 0; i < size; i++) {
        if(arr[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
void StringContainer::del(char elem)
{
    int index = this->findIndex(elem);
    if(index >= 0)
    {
        char * tempArr = arr;
        
        arr = new char[capacity];
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
std::ostream& StringContainer::print(std::ostream& os)
{
    for (size_t i = 0; i < size; i++) {
        os << arr[i] << " ";
    }
    os << std::endl;
    return os;
}
std::istream& StringContainer::read(std::istream& is, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if(this->size + 1 == this->capacity) resize();
        is >> arr[i];
        this->size++;
    }
    arr[size] = '\0';
    return is;
}
char StringContainer::operator [](const int index) const
{
    if(index >= 0 && index < size) return arr[index];
}
int StringContainer::length() const
{
    return this->size;
}