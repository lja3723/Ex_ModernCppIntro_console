#include "Rect.h"

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
Rect::Rect(int)
{
}

Rect::operator int()
{
	return 0;
}

//�Ҹ���
Rect::~Rect()
{
}

//����
void Rect::moveTo(int, int)
{
}
bool Rect::includes(const int, const int)
{
	return false;
}
int Rect::area() const
{
	return (lowerRightX - upperLeftX) * (lowerRightY - upperLeftY);
}

//������ �����ε�
bool Rect::operator>(const Rect&)
{
	return false;
}
Rect& Rect::operator++()
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return *this;
}
Rect Rect::operator++(int)
{
	return Rect();
}

//�����Լ�
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

//�����Լ�
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
Rect& operator--(Rect& rhs)
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return rhs;
}
Rect operator--(Rect&, int)
{
	return Rect();
}
std::ostream& operator<<(std::ostream& os, const Rect&)
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return os;
}
