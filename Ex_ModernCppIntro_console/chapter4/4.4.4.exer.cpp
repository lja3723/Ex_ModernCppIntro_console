#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
using std::string; using std::shared_ptr;
using std::static_pointer_cast;
using std::cout; using std::endl;
using std::ostream;

class CoinMoney {
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{
		//cout << "CoinMoney default ctor" << endl;
	}
	CoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc)
	{
		//cout << "CoinMoney ctor" << endl;
	}
	virtual ~CoinMoney()
	{
		//cout << "CoinMoney dtor" << endl;
	}

	virtual int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
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
	os << "50원 " << m.get_c50() << "개, "
		<< "100원 " << m.get_c100() << "개, "
		<< "500원 " << m.get_c500() << "개, "
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

class MyCoinMoney : public  CoinMoney
{
public:
	MyCoinMoney(int nc, int c, int cc, int ccc, string name)
		: CoinMoney(c, cc, ccc), c10(nc), owner(name)
	{
		//cout << "MyCoiMoney ctor" << endl;
	}
	~MyCoinMoney()
	{
		//cout << "MyCoinMoney dtor" << endl;
	}

	virtual int get_value() const override
	{
		return 10 * c10 + CoinMoney::get_value();
	}
	int get_c10() const
	{
		return c10;
	}
	void set_c10(int c)
	{
		c10 = c;
	}

	string get_owner() const { return owner; }

	friend ostream& operator<<(ostream& os, const MyCoinMoney& c);
protected:

	int c10;
	string owner;
};

ostream& operator<<(ostream& os, const MyCoinMoney& c)
{
	os << c.owner << ": "
		<< "10원 " << c.c10 << "개, ";
	return os << static_cast<const CoinMoney&>(c);
}

int main()
{
	MyCoinMoney m1{ 1, 2, 3, 4, "doohun" };
	MyCoinMoney m2{ 2, 3, 4, 5, "doohun" };
	MyCoinMoney m3{ 3, 4, 2, 1, "doohun" };
	MyCoinMoney m4{ 3, 2, 4, 3, "youngmi" };
	MyCoinMoney m5{ 2, 4, 3, 2, "doohun" };
	MyCoinMoney m6{ 3, 4, 4, 3, "youngmi" };
	std::vector<MyCoinMoney> vec{ m1, m2, m3, m4, m5, m6 };

	std::vector<MyCoinMoney>::iterator it;
	string name = "doohun";

	it = vec.begin();
	while (true)
	{
		it = std::find_if(it, vec.end(), [name](auto& m) { return name == m.get_owner();} );
		if (it == vec.end())
			break;

		cout << *it;
		it++;
	}

	int sum = std::accumulate(vec.begin(), vec.end(), 0, [name](int sum, MyCoinMoney& m) {
		if (m.get_owner() == name)
			return sum + m.get_value();
		else
			return sum;
	});

	cout << name << "'s total is " << sum << endl;

	return 0;
}