#include "String.h"

void String::copy(const String& other) {
	this->data = new char[strlen(other.data) + 1];
	strcpy(this->data, other.data);
}

void String::destroy() {
	delete[] this->data;
}

String::String() {
	this->data = NULL;
}
String::String(const char* data) {
	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
}

String::String(const String& other) {
	copy(other);
}

String& String::operator=(const String& other) {
	if(this != &other) {
		destroy();
		copy(other);
	}
}

String::~String() {
	destroy();
}

char String::at(size_t idx) const {
	assert(("Invalid index provided!", size() > idx));
	return this->data[idx];
}

size_t String::size() const {
	return strlen(this->data);
}

char& String::operator[](size_t idx) {
	assert(("Invalid index provided!", size() > idx));
	return this->data[idx];
}

const char String::operator[](size_t idx) const {
	return at(idx);
}

String& String::operator+=(const String& rhs) {
	char* temp = new char[strlen(this->data) + strlen(rhs.data) + 1];
	int length = 0;
	for (int i = 0; i < strlen(this->data); i++, length++) {
		temp[length] = this->data[i];
	}
	for (int i = 0; i < strlen(rhs.data); i++, length++) {
		temp[length] = rhs[i];
	}
	temp[length] = '\0';
	delete[] this->data;
	this->data = temp;
	return *this;
}

bool String::operator<(const String& rhs) {
	return strcmp(this->data, rhs.data) == -1;
}
bool String::operator>(const String& rhs) {
	return strcmp(this->data, rhs.data) == 1;
}

bool String::operator<=(const String& rhs) {
	return strcmp(this->data, rhs.data) != -1;
}
bool String::operator>=(const String& rhs) {
	return strcmp(this->data, rhs.data) != 1;
}
bool String::operator==(const String& rhs) {
	return strcmp(this->data, rhs.data) == 0;
}
bool String::operator!=(const String& rhs) {
	return !(*this == rhs);
}
String operator+(String lhs, const String& rhs) {
	String result(lhs);
	result += rhs;
	return result;
}

ostream& operator<<(ostream& os, const String& obj) {
	return os << obj.data;
}

istream& operator >> (istream& is, String& obj) {
	char buffer[BUFFER_CAPACITY];
    is >> buffer;
    is.ignore();
	//is.getline(buffer, BUFFER_CAPACITY);

	delete[] obj.data;
	obj.data = new char[strlen(buffer) + 1];
	strcpy(obj.data, buffer);
	return is;
}

const char * String::c_string()
{
    return data;
}