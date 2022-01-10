#include "Rect.h"
#include <algorithm>
#include <vector>
#include <iostream>

using std::cout; using std::endl;

int main()
{
	// 사각형을 담을 vector
	cout << "-- 사각형 벡터 --" << endl;
	std::vector<Rect> rectVector;
	Rect aRect(30, 40, 70, 70);	// area = 1200
	Rect bRect(100, 90, 130, 150); // area = 1800
	Rect cRect(20, 30, 50, 50); // area = 600
	Rect dRect(100, 100, 150, 150); // area = 2500
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	rectVector.push_back(dRect);

	//면적이 1500 이상인 척 번째 사각형 찾기
	auto findRect = std::find_if(rectVector.begin(), rectVector.end(), [](Rect& r) { return r.area() >= 2501; });

	if (findRect != rectVector.end())
		cout << "면적이 1500보다 큰 첫 사각형은 " << *findRect;
	else
		cout << "면적이 1500보다 큰 사각형 없음" << endl;

	cout << 2[rectVector] << endl;

	return 0;
}