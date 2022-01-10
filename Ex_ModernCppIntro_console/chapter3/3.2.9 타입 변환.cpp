#include <iostream>
#include <cstring>
void print(char* str)
{
	str[6] = '_';
	std::cout << str << std::endl;
}

int main(void)
{
	//자동 타입 변환
	std::cout << "implicit type conversion" << std::endl;
	short a = 3;
	int b = 4;
	long c = a * b;
	std::cout << c << std::endl;

	//수동 타입 변환(타입 캐스팅)
	std::cout << "explicit type conversion" << std::endl;
	int x = 5;
	double y = 3.14;
	y = double(x) + y;
	std::cout << y << std::endl;

	//포인터 변수의 타입 변환
	std::cout << "type conversion of pointers" << std::endl;
	int* i = new int(7);
	void* v;
	v = i;
	int* j = static_cast<int*>(v);
	std::cout << *j << std::endl;

	//const_cast 예제
	char cstr[32];
	strcpy_s(cstr, "sample text");
	print(const_cast<char*>(cstr));

	return 0;
}