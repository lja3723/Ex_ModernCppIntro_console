#include <cstdio>
#include <iostream>
using std::cout; using std::endl;

// structure for CoinMoney - three int members
struct CoinMoney {
	int c50;
	int c100;
	int c500;
};

inline int CoinMoney_value(const CoinMoney& m)
{
	return (50 * m.c50 + 100 * m.c100 + 500 * m.c500);
}

CoinMoney CoinMoney_add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.c50 = m1.c50 + m2.c50;
	sum.c100 = m1.c100 + m2.c100;
	sum.c500 = m1.c500 + m2.c500;
	return sum;
}

void CoinMoney_print(const CoinMoney& m)
{
	//printf("50원 %d개, 100원 %d개, 500원 %d개, 총 %d원\n",
	//	m.c50, m.c100, m.c500, CoinMoney_value(m));

	cout << "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << CoinMoney_value(m) << "원" << endl;

}

int main()
{
	CoinMoney m1, m2, m3;	// three CoinMoney variables
	int get_value;
	m1.c50 = 1;						// initialize m1
	m1.c100 = 2;
	m1.c500 = 3;
	printf("m1 = ");
	CoinMoney_print(m1);			// print m1
	m2 = m1;						// can assign struct to each other
	printf("m2 = ");				// print m2
	CoinMoney_print(m2);			// m2 is now a copy of m1
	get_value = CoinMoney_value(m1);	// get and print m1's total value
	printf("m1은 ");
	printf("총 %d원\n", get_value);
	m3 = CoinMoney_add(m1, m2);		// add m1 & m2, store in m3
	printf("m3 = ");				// print m3
	CoinMoney_print(m3);

	return 0;
}