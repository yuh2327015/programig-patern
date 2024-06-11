#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void Eventhandler()
{
    cout << "함수포인터" << endl;
}

int main()
{

    void (*onCollisionEnter)();
    
    onCollisionEnter = Eventhandler;
    onCollisionEnter();
    
}
