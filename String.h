
#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

const size_t BUFFER_CAPACITY = 1000;


class String {
private:
	char* data;

	void copy(const String& other);
	void destroy();
public:
	String();
	String(const char* data);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	char at(size_t idx) const;
	size_t size() const;

	char& operator[](size_t idx);
	const char operator[](size_t idx) const;
    const char * c_string();
	String& operator+=(const String& rhs);
	bool operator<(const String& rhs);
	bool operator>(const String& rhs);
	bool operator<=(const String& rhs);
	bool operator>=(const String& rhs);

	bool operator==(const String& rhs);
	bool operator!=(const String& rhs);
	
	friend String operator+(String lhs, const String& rhs);
	friend ostream& operator<<(ostream& os, const String& obj);
	friend istream& operator>>(istream& is, String& obj);

};


