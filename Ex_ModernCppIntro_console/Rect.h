#pragma once
#include <iostream>

class Rect {
public:
	//������ �Լ�
	Rect(int, int, int, int);
	Rect();

	//Ÿ�� ĳ����
	explicit Rect(int);
	operator int();

	//�Ҹ���
	virtual ~Rect();

	//����
	void moveTo(int, int);
	bool includes(const int, const int);
	int area() const;
	int getWidth() const;
	int getHeight() const;

	//������ �����ε�
	bool operator>(const Rect&);
	Rect& operator++();
	Rect operator++(int);

	//�����Լ�
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getLowerRightX() const;
	int getLowerRightY() const;

	//�����Լ�
	void setUpperLeftX(int x);
	void setUpperLeftY(int y);
	void setLowerRightX(int x);
	void setLowerRightY(int y);

protected:
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};

extern bool operator<(const Rect&, const Rect&);
extern Rect& operator--(Rect&);
extern Rect operator--(Rect&, int);

//console version
extern std::ostream& operator<<(std::ostream&, const Rect&);