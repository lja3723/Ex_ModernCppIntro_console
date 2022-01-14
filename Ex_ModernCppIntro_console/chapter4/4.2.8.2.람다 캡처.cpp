#include <iostream>
#include <functional>
using std::cout;
using std::endl;

int main()
{
	int intVal = 43;
	auto lambdaFunc = [intVal]() {
		cout << "this lambda has copy of intVal: " << intVal << endl;
	};
	std::function<void()> lambdaFuncc;

	for (int i = 0; i < 3; i++)
	{
		intVal++;
		lambdaFuncc = [intVal]() {
			cout << "this lambdaFuncc has copy of intVal: " << intVal << endl;
		};
		lambdaFunc();
		lambdaFuncc();
	}

	intVal = 43;
	auto lambdaFunc2 = [&intVal]() {
		cout << "this lambda captures intVal by reference: " << intVal << endl;
	};

	for (int i = 0; i < 3; i++)
	{
		intVal++;
		lambdaFunc2();
	}


	intVal = 43;
	auto lambdaFunc3 = [&intVal]() {
		cout << "this lambda adds 10 to intVal" << endl; intVal += 10;
	};
	lambdaFunc3();
	cout << "intVal: " << intVal << endl;

	int sum = 0;
	for (int i = 0; i < 3; i++)
		[&sum](int x) -> void {sum += x; cout << "sum: " << sum << endl; }(i);


	return 0;
}