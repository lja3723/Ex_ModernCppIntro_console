#include "Rect.h"
#include <string>
#include <tuple>
using std::string;

struct Person
{
	string name;
	int birthDate;
};

void func(Person& p)
{
	cout << "Person&" << endl;
}

void func(Person&& p)
{
	cout << "Person&&" << endl;
}

int main(void)
{
	cout << "student1-----" << endl;
	Person p1{ "wonjin", 820301 };
	std::tuple<int, string, Person> student1 =
		std::tuple<int, string, Person>(20167777, "cs", p1);
	cout << std::get<1>(student1) << endl;
	cout << std::get<2>(student1).name << endl;


	cout << "student2-----" << endl;
	Person p2{ "doohun", 830117 };
	std::tuple<int, string, Person> student2 = std::make_tuple(20168888, "english", p2);
	cout << std::get<2>(student2).birthDate << endl;
	auto count = std::tuple_size<decltype(student2)>::value;
	cout << count << endl;

	
	cout << "student3-----" << endl;
	Person p3{ "youngmi", 830117 };
	std::tuple<int, string, Person> student3;
	std::get<0>(student3) = 20173333;
	std::get<1>(student3) = "fashion design";
	std::get<2>(student3) = p3;
	cout << std::get<1>(student3) << endl;
	cout << std::get<2>(student3).name << endl;


	cout << "Rect Class-----" << endl;
	Rect theRect(30, 40, 50, 70);
	string rectName("the rectangle");
	auto rect = std::tie(rectName, theRect);
	std::get<0>(rect) = "smart rectangle";
	cout << rectName << endl;
	auto rectOwner = std::tuple_cat(student1, rect);
	cout << std::get<2>(student1).name << "'s rectangle is " << std::get<3>(rectOwner) << endl;
	
	return 0;
}