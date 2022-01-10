#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <functional>

using namespace std;

class Obj
{
public:
	int rank;    //���� ���� �켱
	int speed;   //ū ���� �켱
	int version; //ū ���� �켱

	Obj(int _rank, int _speed, int _version)
		: rank(_rank), speed(_speed), version(_version)
	{}

	//invalid comparator ��Ÿ�� ���� �߻�!
	/*bool operator<(const Obj& o)
	{
		if (rank < o.rank)
			return true;
		else if (speed > o.speed)
			return true;
		else if (version > o.version)
			return true;
		return false;
	}*/

	bool operator<(const Obj& o)
	{
		if (rank < o.rank)
			return true;
		else if (rank == o.rank && speed > o.speed)
			return true;
		else if (rank == o.rank && speed == o.speed && version > o.version)
			return true;
		return false;
	}
};

void print(vector<Obj>& vec)
{
	auto vec_size = vec.size();
	cout << "rank \tspeed \tversion" << endl;
	for (int i = 0; i < vec_size; i++)
		cout << vec[i].rank << "\t" << vec[i].speed << "\t" << vec[i].version << endl;
	cout << "\n\n";
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disRank(0, 15);		//rank�� ������ [0, 15] int
	std::uniform_int_distribution<int> disSpeed(0, 49);		//���ϵ���
	std::uniform_int_distribution<int> disVersion(1, 29);	//���ϵ���

	const int vec_size = 1000;
	std::vector<Obj> vec;
	//rank, speed, version�� �������̰� ����������
	for (int i = 0; i < vec_size; i++)
		vec.push_back(Obj(disRank(gen), disSpeed(gen) * 100, disVersion(gen)));

	cout << "=======after sort========" << endl;
	std::sort(vec.begin(), vec.end(), std::greater<>());
	print(vec);

	return 0;
}