#include <iostream>
#include <string>
#include <memory>

using std::string;

int main(void)
{
	std::shared_ptr<string> sp1(new string("lja"));
	std::shared_ptr<string> sp2 = sp1;
	std::weak_ptr<string> wp1 = sp2;

	{
		std::shared_ptr<string> sp3 = wp1.lock();
		if (sp3) {
			std::cout << "wp1을 통해 sp3 복사 완료" << std::endl;
		}
		std::shared_ptr<int> sp4 = std::make_shared<int>(10);
		std::weak_ptr<string> wp2(sp1);
	}

	std::cout << "sp1이 가리키는 문자열 출력: " << *sp1 << std::endl;
	sp1.reset();
	std::shared_ptr<string> sp5 = wp1.lock();
	sp2 = nullptr;

	if (sp5 != nullptr) {
		std::cout << "이 문장은 실행될까?" << std::endl;
		std::cout << "실행 된다면," << *sp5 << std::endl;
	}

	wp1.reset();

	return 0;
}