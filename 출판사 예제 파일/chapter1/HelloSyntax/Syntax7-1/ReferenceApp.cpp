#include <iostream>
using std::cout;
using std::endl;

int greater(int& a, int& b)
{
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
		return 1;
	}
	else
		return 0;
}

int main() {
	int i = 20, j = 10, k;
	k = greater(i, j);
	cout << "i=" << i << " j=" << j << endl;

	return 0;
}