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

std::shared_ptr<CoinMoney> CoinMoney_add(const std::shared_ptr<CoinMoney> m1, const std::shared_ptr<CoinMoney> m2)
{
	std::shared_ptr<CoinMoney> psum(new CoinMoney());
	psum->c50 = m1->c50 + m2->c50;
	psum->c100 = m1->c100 + m2->c100;
	psum->c500 = m1->c500 + m2->c500;
	return psum;
}

void CoinMoney_print(const CoinMoney& m)
{
	//printf("50�� %d��, 100�� %d��, 500�� %d��, �� %d��\n",
	//	m.c50, m.c100, m.c500, CoinMoney_value(m));

	cout << "50�� " << m.c50 << "��, "
		<< "100�� " << m.c100 << "��, "
		<< "500�� " << m.c500 << "��, "
		<< "�� " << CoinMoney_value(m) << "��" << endl;

}

int main()
{
	std::shared_ptr<CoinMoney> sps[3];

	for (int i = 0; i < 3; i++)
	{
		sps[i] = std::make_shared<CoinMoney>();
		sps[i]->c50 = i + 1;
		sps[i]->c100 = i + 2;
		sps[i]->c500 = i + 3;
	}

	for (auto& i : sps)
		CoinMoney_print(*i);

	return 0;
}