#include <iostream>

//using namespace std;

int main()
{	
	int num = 0;
	std::string name;
	std::cout << "이지호 : 아 힘들다..." << std::endl;

	while (num !=18)
	{
		std::cout << "나쁜놈의 이름과 나이를 입력하세요...";
		std::cin >> name >> num;
	}
	
	std::cout << "이지호: 유한상 " << num << "유한상..." << name << "..." << std::endl;
	
	
	return 0;
}

