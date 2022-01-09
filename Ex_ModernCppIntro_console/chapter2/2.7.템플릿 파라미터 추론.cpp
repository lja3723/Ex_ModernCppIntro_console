#include <iostream>

template <typename T>
void foo(T param)
{
	std::cout << __func__ << std::endl;
}

template <typename T>
void foo2(T& param)
{
	std::cout << __func__ << std::endl;
}

template <typename T>
void foo3(const T& param)
{
	std::cout << __func__ << std::endl;
}

template <typename T>
void foo4(T* param)
{
	std::cout << __func__ << std::endl;
}

int main(void)
{
	int x = 23;
	const int cx = x;
	const int& rx = x;
	foo(x);
	foo(cx);
	foo(rx);

	foo2(x);
	foo2(cx);
	foo2(rx);

	foo3(x);
	foo3(cx);
	foo3(rx);

	const int* px = &x;
	foo4(&x);
	foo4(px);
}