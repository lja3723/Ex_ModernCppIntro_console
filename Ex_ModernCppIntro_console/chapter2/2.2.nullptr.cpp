#include <iostream>
using namespace std;

void func(int a)
{
	cout << "func-int" << endl;
}

void func(double* p)
{
	cout << "func-double*" << endl;
}

int main(void)
{
	func(0);
	func(NULL);
	func(static_cast<double*>(NULL));
	func(nullptr);

	return 0;
}