#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::ostream;

class KoreanCoinMoney {
public:
	KoreanCoinMoney(int c, int cc, int ccc) : c50(c), c100(cc), c500(ccc)
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

	int c50;
	int c100;
	int c500;
};

class USCoinMoney
{
public:
	USCoinMoney(int c, int cc, int ccc)
		: nickels(c), dimes(cc), quarters(ccc)
	{}

	//1 dollar == 100 cents;
	double get_value() const
	{
		return 0.05 * nickels + 0.1 * dimes + 0.25 * quarters;
	}

	void print() const
	{
		cout << "nickels "
			<< nickels << "개, dimes "
			<< dimes << "개, quarters "
			<< quarters << "개, 총 $"
			<< get_value() << endl;
	}

	int nickels;	//5 cents
	int dimes;		//10 cents
	int quarters;	//25 cents
};

template <typename CoinType>
class CoinContainer
{
public:
	void addCoin(const CoinType& c) {
		coinVect.push_back(c);
	}
	CoinType topCoin() {
		auto coin = coinVect[coinVect.size() - 1];
		coinVect.pop_back();
		return coin;
	}
	void print() const {
		for (auto& it : coinVect)
			it.print();
	}

private:
	std::vector<CoinType> coinVect;
};

template <class T>
class CoinPair
{
public:
	CoinPair(T a, T b)
		: first(a), second(b)
	{}
	T getMax() const {
		if (first.get_value() < second.get_value())
			return second;
		else
			return first;
	}
private:
	T first, second;
};

int main()
{
	KoreanCoinMoney km1(4, 2, 6); KoreanCoinMoney km2(3, 3, 6);
	CoinPair<KoreanCoinMoney> kPair(km1, km2);
	auto km = kPair.getMax();
	cout << "the greater one is ";
	km.print();

	USCoinMoney um1(4, 5, 6); USCoinMoney um2(5, 4, 6);
	CoinPair<USCoinMoney> uPair(um1, um2);
	auto um = uPair.getMax();
	cout << "the greater one is ";
	um.print();

	return 0;
}