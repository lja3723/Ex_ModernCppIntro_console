// 연습 문제 1을 발전시킴
// copy assignment
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::string; using std::to_string;
using std::exception; using std::logic_error;

class ArrayException : public logic_error
{
public:
	ArrayException(const string& msg)
		: logic_error(msg), message(msg)
	{}

	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
	// data field
protected:
	string message;
};

class Array
{
public:
	Array()
		: size(0), ptr(nullptr), serial_number(++counter)
	{
		cout << "배열 " << serial_number << " default 생성" << endl;
	}

	Array(int s)
		: size(s), serial_number(++counter)
	{
		if (size < 0)
			throw ArrayException("배열 크기는 0 이상: " + to_string(size));
		ptr = new int[size];
		cout << "배열 " << serial_number << " 생성" << endl;
	}

	~Array()
	{
		delete[] ptr;
		cout << "배열 " << serial_number << " 소멸" << endl;
	}
	// Exer: copy assignment
	Array& operator=(const Array& original)
	{
		if (this == &original)
			return *this;
		delete[] ptr;
		size = original.size; ptr = new int[size];
		for (int i = 0; i < size; i++)
			ptr[i] = original.ptr[i];
		cout << "배열 " << serial_number << "에 배열 "
			<< original.serial_number << " copy 배정" << endl;
	}

	int getSerial_number() const
	{ return serial_number; }

	int get_size() const
	{ return size; }

	int& operator[](int index)
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("크기를 벗어남: "+ to_string(index));
		}
		return ptr[index];
	}

	const int& operator[](int index) const
	{
		if (index < 0 || index > size - 1) {
			throw ArrayException("크기를 벗어남: " + to_string(index));
		}
		return ptr[index];
	}
//	Array(const Array& source) = delete;				// Exer
//	Array& operator=(const Array& source) = delete;		// Exer
	// data fields
private:
	int size;
	int* ptr;
	int serial_number;
	static int counter;
};

int Array::counter = 0;

void printem(const Array& a)
{
	for (int i = 0; i < a.get_size(); i++)
		cout << '[' << i << "]: " << a[i] << endl;;
}

int main()
{
	try {
		// default array
		Array a;
		cout << "배열 " << a.getSerial_number() << " 내용:" << endl;
		// call by const reference
		printem(a);
		Array b(5);
		for (int i = 0; i < 5; i++)
			b[i] = i;
		cout << "배열 " << b.getSerial_number() << " 내용:" << endl;
		printem(b);
		// Exer: copy assignment
		cout << "copy assignment **********" << endl;
		a = b;
		cout << "배열 " << a.getSerial_number() << " 내용:" << endl;
		printem(a);
		// Exer: self assignment
		b = b;
	}
	catch (const ArrayException& e) {
		cout << e.what() << endl;
	}

	cout << "Done!" << endl;
	return 0;
}