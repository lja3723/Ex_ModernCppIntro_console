#include "Rect.h"
#include <algorithm>
#include <vector>
#include <iostream>

using std::cout; using std::endl;

int main()
{
	// �簢���� ���� vector
	cout << "-- �簢�� ���� --" << endl;
	std::vector<Rect> rectVector;
	Rect aRect(30, 40, 70, 70);	// area = 1200
	Rect bRect(100, 90, 130, 150); // area = 1800
	Rect cRect(20, 30, 50, 50); // area = 600
	Rect dRect(100, 100, 150, 150); // area = 2500
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	rectVector.push_back(dRect);

	//������ 1500 �̻��� ô ��° �簢�� ã��
	auto findRect = std::find_if(rectVector.begin(), rectVector.end(), [](Rect& r) { return r.area() >= 2501; });

	if (findRect != rectVector.end())
		cout << "������ 1500���� ū ù �簢���� " << *findRect;
	else
		cout << "������ 1500���� ū �簢�� ����" << endl;

	cout << 2[rectVector] << endl;

	return 0;
}