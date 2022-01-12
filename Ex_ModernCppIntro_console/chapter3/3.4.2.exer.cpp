#include <iostream>
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

	//operator overloading
	CoinMoney operator+(const CoinMoney& rhs)
	{
		CoinMoney sum;
		sum.set_c50(c50 + rhs.c50);
		sum.set_c100(c100 + rhs.c100);
		sum.set_c500(c500 + rhs.c500);
		return sum;
	}

	bool operator==(const CoinMoney& rhs)
	{
		return (c50 == rhs.c50) && (c100 == rhs.c100) && (c500 == rhs.c500);
	}

	bool operator!=(const CoinMoney& rhs)
	{
		return !(*this == rhs);
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
CoinMoney operator-(const CoinMoney& lhs, const CoinMoney& rhs)
{
	CoinMoney diff;
	diff.set_c50(lhs.get_c50() - rhs.get_c50());
	diff.set_c100(lhs.get_c100() - rhs.get_c100());
	diff.set_c500(lhs.get_c500() - rhs.get_c500());
	return diff;
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
	CoinMoney m1{ 2, 0, 1 }, m2, m3;
	cout << "m1 = " << m1;
	m2 = m1;
	m2.set_c100(3);
	cout << "m2 = " << m2;

	if (m1 != m2)
		cout << "m1 and m2 are not equal" << endl;

	m3 = (m2 + m3) - m1;
	cout << "m3 = " << m3;

	return 0;
}