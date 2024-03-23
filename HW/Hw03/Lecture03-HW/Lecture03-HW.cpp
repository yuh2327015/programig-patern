#include <iostream>

enum ForeColor {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

void drawBlock(int color) {
    std::cout << "\033[" << color << "m";
    std::cout << "■■■■■\n";
    std::cout << "■■■■■\n";
    std::cout << "■■■■■\n";
    std::cout << "■■■■■\n";
    std::cout << "■■■■■\n";
    std::cout << "\033[" << ForeColor ::Default << "m";
}

int main()
{
    std::cout << "흰색 블록을 그리는 키코드 : 1\n";
    std::cout << "빨강색 블록을 그리는 키코드 : 2\n";
    std::cout << "녹색 블록을 그리는 키코드 : 4 \n";
    std::cout << "노란색 블록을 그리는 키코드 : 8 \n";
    std::cout << "청록색 블록을 그리는 키코드 : 16 \n";
    std::cout << "마젠타색 블록을 그리는 키코드 : 32\n";
    std::cout << "프로그램 종료 : 64\n\n";
    std::cout << "학번 : 202327015\n";
    std::cout << "이름 : 우성윤\n";
   
    int userInput;  
    do {
        std::cout << "화면에 그릴 물체코드를 입력하세요 : ";
        std::cin >> userInput;
        switch (userInput)
        {
        case 1:
            drawBlock(ForeColor::White);
            break;
        case 2:
            drawBlock(ForeColor::Red);
            break;
        case 4:
            drawBlock(ForeColor::Green);
            break;
        case 8:
            drawBlock(ForeColor::Yellow);
            break;
        case 16:
            drawBlock(ForeColor::Cyan);
            break;
        case 32:
            drawBlock(ForeColor::Magenta);
            break;
        case 64:
            std::cout << "프로그램을 종료합니다.\n";
            break;
        default:
            std::cout << "잘못된 입력입니다. 다시 시도하세요.\n";
            break;
        }
    } while (userInput != 64);
    return 0;
}