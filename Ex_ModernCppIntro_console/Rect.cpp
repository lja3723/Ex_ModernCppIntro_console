#include "Rect.h"

//생성자 함수
Rect::Rect(int, int, int, int)
{
}
Rect::Rect()
{
}

//타입 캐스팅
Rect::Rect(int)
{
}
Rect::operator int()
{
}

//소멸자
Rect::~Rect()
{
}

//연산
void Rect::moveTo(int, int)
{
}
bool Rect::includes(const int, const int)
{
	return false;
}
int Rect::area() const
{
	return 0;
}

//연산자 오버로딩
bool Rect::operator>(const Rect&)
{
	return false;
}
Rect& Rect::operator++()
{
	// TODO: 여기에 return 문을 삽입합니다.
}
Rect Rect::operator++(int)
{
	return Rect();
}

//접근함수
int Rect::getUpperLeftX() const
{
	return 0;
}
int Rect::getUpperLeftY() const
{
	return 0;
}
int Rect::getLowerRightX() const
{
	return 0;
}
int Rect::getLowerRightY() const
{
	return 0;
}

//변경함수
void Rect::setUpperLeftX()
{
}
void Rect::setUpperLeftY()
{
}
void Rect::setLowerRightX()
{
}
void Rect::setLowerRightY()
{
}


bool operator<(const Rect&, const Rect&)
{
	return false;
}
Rect& operator--(Rect&)
{
	// TODO: 여기에 return 문을 삽입합니다.
}
Rect operator--(Rect&, int)
{
	return Rect();
}
std::ostream& operator<<(std::ostream&, const Rect&)
{
	// TODO: 여기에 return 문을 삽입합니다.
}
