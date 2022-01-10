#include <iostream>
#include <cstring>
void print(char* str)
{
	str[6] = '_';
	std::cout << str << std::endl;
}

int main(void)
{
	//�ڵ� Ÿ�� ��ȯ
	std::cout << "implicit type conversion" << std::endl;
	short a = 3;
	int b = 4;
	long c = a * b;
	std::cout << c << std::endl;

	//���� Ÿ�� ��ȯ(Ÿ�� ĳ����)
	std::cout << "explicit type conversion" << std::endl;
	int x = 5;
	double y = 3.14;
	y = double(x) + y;
	std::cout << y << std::endl;

	//������ ������ Ÿ�� ��ȯ
	std::cout << "type conversion of pointers" << std::endl;
	int* i = new int(7);
	void* v;
	v = i;
	int* j = static_cast<int*>(v);
	std::cout << *j << std::endl;

	//const_cast ����
	char cstr[32];
	strcpy_s(cstr, "sample text");
	print(const_cast<char*>(cstr));

	return 0;
}