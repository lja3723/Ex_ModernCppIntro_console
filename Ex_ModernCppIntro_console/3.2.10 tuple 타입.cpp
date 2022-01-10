#include "Rect.h"
#include <string>
#include <tuple>
using std::string; using std::tuple;
using std::make_tuple; using std::get;
using std::tuple_size;

struct Person
{
	string name;
	int birthDate;
};

int main(void)
{
	Person p1{ "wonjin", 820301 };
	cout << p1.name << ", " << p1.birthDate << endl;
	
	return 0;
}