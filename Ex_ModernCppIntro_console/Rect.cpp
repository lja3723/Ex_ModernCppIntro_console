#include "Rect.h"
#include <cmath>

//������ �Լ�
Rect::Rect(int tlX, int tlY, int brX, int brY)
	: upperLeftX(tlX), upperLeftY(tlY), lowerRightX(brX), lowerRightY(brY)
{
}
Rect::Rect()
	: upperLeftX(100), upperLeftY(100), lowerRightX(200), lowerRightY(200)
{
}

//Ÿ�� ĳ����
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

//�Ҹ���
Rect::~Rect()
{
}

//����
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

//������ �����ε�
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

//�����Լ�
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

//�����Լ�
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
	os << "��ġ:(" << r.getUpperLeftX() << ", " << r.getUpperLeftY() << ")";
	os << " ��:" << r.getWidth();
	os << " ����:" << r.getHeight();
	// TODO: ���⿡ return ���� �����մϴ�.
	return os;
}