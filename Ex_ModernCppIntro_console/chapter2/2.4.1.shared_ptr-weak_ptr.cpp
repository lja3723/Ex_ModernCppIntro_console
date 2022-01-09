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
			std::cout << "wp1�� ���� sp3 ���� �Ϸ�" << std::endl;
		}
		std::shared_ptr<int> sp4 = std::make_shared<int>(10);
		std::weak_ptr<string> wp2(sp1);
	}

	std::cout << "sp1�� ����Ű�� ���ڿ� ���: " << *sp1 << std::endl;
	sp1.reset();
	std::shared_ptr<string> sp5 = wp1.lock();
	sp2 = nullptr;

	if (sp5 != nullptr) {
		std::cout << "�� ������ ����ɱ�?" << std::endl;
		std::cout << "���� �ȴٸ�," << *sp5 << std::endl;
	}

	wp1.reset();

	return 0;
}