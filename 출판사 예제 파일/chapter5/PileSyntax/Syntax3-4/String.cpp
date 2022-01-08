#include "String.h"
#include <cstring>

String::String(const char* cstr)
{
	if (cstr == nullptr)
		length = 1;
	else
		length = strlen(cstr) + 1;
	s = new char[length];
	if (cstr != nullptr)
		strcpy(s, cstr);
}

String::String(const String& str)
{
	length = str.length;
	s = new char[length];
	strcpy(s, str.s);
}

String::String(String&& str)
{
	length = str.length;
	s = str.s;
	str.s = nullptr;
}

String::~String()
{
	delete[] s;
}

String::operator char*()
{
	return s;
}

String& String::operator=(const String& str)
{
	if (this == &str)
		return *this;
	delete[] s;
	length = str.length;
	s = new char[length];
	strcpy(s, str.s);
	return *this;
}

String& String::operator=(String&& str)
{
	if (this == &str)
		return *this;
	delete[] s;
	length = str.length;
	s = str.s;
	str.s = nullptr;
	return *this;
}

String String::operator+(const String& str)
{
	char* temp = new char[length + str.length - 1];
	strcpy(temp, s);
	strcat(temp, str.s);
	String tempStr(temp);
	delete[] temp;
	return tempStr;
}

bool String::operator==(const String& str)
{
	return strcmp(s, str.s) ? false : true;
}