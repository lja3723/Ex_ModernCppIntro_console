#include <iostream>
#include <vector>
#include <algorithm>
using std::cout; using std::endl;
using std::ostream;

class CoinMoney {
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{}
	CoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc)
	{}
	virtual ~CoinMoney()
	{}

	int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}

	/*void print() const
	{
		cout << "50원 "
			<< c50 << "개, 100원 "
			<< c100 << "개, 500원 "
			<< c500 << "개, 총 "
			<< get_value() << "원" << endl;
	}*/

	bool operator<(const CoinMoney& m)
	{
		return get_value() < m.get_value();
	}


	//getters
	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	//setters
	void set_c50(int c) { c50 = c; }
	void set_c100(int c) { c100 = c; }
	void set_c500(int c) { c500 = c; }

protected:
	int c50;
	int c100;
	int c500;
};

//global function
CoinMoney add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}

ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50원 "
		<< m.get_c50() << "개, 100원 "
		<< m.get_c100() << "개, 500원 "
		<< m.get_c500() << "개, 총 "
		<< m.get_value() << "원" << endl;
	return os;
}

int main()
{
	CoinMoney m1(1, 2, 3); CoinMoney m2(4, 2, 1);
	CoinMoney m3(3, 2, 4); CoinMoney m4(6, 3, 1);
	CoinMoney m5(3, 3, 4); CoinMoney m6(5, 2, 1);

	std::vector<CoinMoney> coinVec{ m1, m2, m3, m4, m5, m6 };

	for (const CoinMoney& c : coinVec)
		cout << c;

	std::sort(coinVec.begin(), coinVec.end());

	cout << "after ascending sort" << endl;

	for (const CoinMoney& c : coinVec)
		cout << c;

	return 0;
}