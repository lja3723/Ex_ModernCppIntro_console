#include "Rect.h"

//������ �Լ�
Rect::Rect(int, int, int, int)
{
}
Rect::Rect()
{
}

//Ÿ�� ĳ����
Rect::Rect(int)
{
}
Rect::operator int()
{
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
	return 0;
}

//������ �����ε�
bool Rect::operator>(const Rect&)
{
	return false;
}
Rect& Rect::operator++()
{
	// TODO: ���⿡ return ���� �����մϴ�.
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
Rect& operator--(Rect&)
{
	// TODO: ���⿡ return ���� �����մϴ�.
}
Rect operator--(Rect&, int)
{
	return Rect();
}
std::ostream& operator<<(std::ostream&, const Rect&)
{
	// TODO: ���⿡ return ���� �����մϴ�.
}
