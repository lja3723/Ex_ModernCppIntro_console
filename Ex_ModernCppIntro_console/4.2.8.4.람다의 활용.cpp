#include "Rect.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	vector<Rect> rectVector;
	Rect aRect(30, 40, 70, 70);
	Rect bRect(100, 90, 130, 150);
	Rect cRect(20, 30, 50, 50);
	Rect dRect(100, 100, 150, 150);
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	rectVector.push_back(dRect);
	
	vector<Rect>::iterator findRect;
	findRect = find_if(rectVector.begin(), rectVector.end(), 
		[compareArea = 2000](auto& r) { return (r.area() >= compareArea); }
	);

	if (findRect != rectVector.end())
		cout << "면적이 2000보다 큰 첫 사각형은 " << *findRect << endl;

	return 0;
}