#pragma once
#include <iostream>

class Rect {
public:
	//생성자 함수
	Rect(int, int, int, int);
	Rect();

	//타입 캐스팅
	explicit Rect(int);
	operator int();

	//소멸자
	virtual ~Rect();

	//연산
	void moveTo(int, int);
	bool includes(const int, const int);
	int area() const;
	int getWidth() const;
	int getHeight() const;

	//연산자 오버로딩
	bool operator>(const Rect&);
	Rect& operator++();
	Rect operator++(int);

	//접근함수
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getLowerRightX() const;
	int getLowerRightY() const;

	//변경함수
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