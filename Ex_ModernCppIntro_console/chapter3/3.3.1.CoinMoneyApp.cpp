#include <iostream>
using std::cout; using std::endl;
using std::ostream;

class KoreanCoinMoney {
public:
	KoreanCoinMoney() : c50(0), c100(0), c500(0)
	{}
	KoreanCoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc)
	{}
	virtual ~KoreanCoinMoney()
	{}

	int get_value() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}

	void print() const
	{
		cout << "50원 "
			<< c50 << "개, 100원 "
			<< c100 << "개, 500원 "
			<< c500 << "개, 총 "
			<< get_value() << "원" << endl;
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
KoreanCoinMoney add(const KoreanCoinMoney& m1, const KoreanCoinMoney& m2)
{
	KoreanCoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}

ostream& operator<<(ostream& os, const KoreanCoinMoney& m)
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
	KoreanCoinMoney m1(1, 2, 3);
	KoreanCoinMoney m2, m3;	

	printf("m1 = ");
	m1.print();			

	printf("m2 = ");
	m2.set_c50(1);
	m2.set_c100(2);
	m2.set_c500(3);
	m2.print();
	cout << "m1은 " << m1.get_value() << "원\n";

	m3 = add(m1, m2);	
	printf("m3 = ");
	m3.print();

	return 0;
}