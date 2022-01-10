#include "Rect.h"
#include <cmath>

//생성자 함수
Rect::Rect(int tlX, int tlY, int brX, int brY)
	: upperLeftX(tlX), upperLeftY(tlY), lowerRightX(brX), lowerRightY(brY)
{
}
Rect::Rect()
	: upperLeftX(100), upperLeftY(100), lowerRightX(200), lowerRightY(200)
{
}

//타입 캐스팅
Rect::Rect(int x)
	: upperLeftX(100), upperLeftY(100)
{
	int length = static_cast<int>(sqrt(static_cast<double>(x)));
	lowerRightX = upperLeftX + length;
	lowerRightY = upperLeftY + length;
}
Rect::operator int()
{
	return area();
}

//소멸자
Rect::~Rect()
{
}

//연산
void Rect::moveTo(int x, int y)
{
	int width = getWidth();
	int height = getHeight();
	upperLeftX = x;
	upperLeftY = y;
	lowerRightX = x + width;
	lowerRightY = y + height;
}
bool Rect::includes(const int x, const int y)
{
	if (upperLeftX < x && x < lowerRightX)
		if (upperLeftY < y && y < lowerRightY)
			return true;
	return false;
}
int Rect::area() const
{
	return getWidth() * getHeight();
}
int Rect::getWidth() const
{
	return lowerRightX - upperLeftX;
}
int Rect::getHeight() const
{
	return lowerRightY - upperLeftY;
}

//연산자 오버로딩
bool Rect::operator>(const Rect& rhs)
{
	return area() > rhs.area();
}
Rect& Rect::operator++()
{
	++lowerRightX;
	++lowerRightY;
	return *this;
}
Rect Rect::operator++(int k)
{
	Rect temp(upperLeftX, upperLeftY, lowerRightX, lowerRightY);
	++(*this);
	return temp;
}

//접근함수
int Rect::getUpperLeftX() const
{
	return upperLeftX;
}
int Rect::getUpperLeftY() const
{
	return upperLeftY;
}
int Rect::getLowerRightX() const
{
	return lowerRightX;
}
int Rect::getLowerRightY() const
{
	return lowerRightY;
}

//변경함수
void Rect::setUpperLeftX(int x)
{
	upperLeftX = x;
}
void Rect::setUpperLeftY(int y)
{
	upperLeftY = y;
}
void Rect::setLowerRightX(int x)
{
	lowerRightX = x;
}
void Rect::setLowerRightY(int y)
{
	lowerRightY = y;
}


bool operator<(const Rect& lhs, const Rect& rhs)
{
	return lhs.area() < rhs.area();
}
Rect& operator--(Rect& rhs)
{
	rhs.setLowerRightX(rhs.getLowerRightX() - 1);
	rhs.setLowerRightY(rhs.getLowerRightY() - 1);
	return rhs;
}
Rect operator--(Rect& rhs, int k)
{
	Rect temp(rhs);
	--rhs;
	return temp;
}
std::ostream& operator<<(std::ostream& os, const Rect& r)
{
	os << "위치:(" << r.getUpperLeftX() << ", " << r.getUpperLeftY() << ")";
	os << " 폭:" << r.getWidth();
	os << " 높이:" << r.getHeight();
	// TODO: 여기에 return 문을 삽입합니다.
	return os;
}