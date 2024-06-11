#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void Eventhandler()
{
    cout << "끄아아아악" << endl;
}

int main()
{

    void (*onCollisionEnter)();
    
    onCollisionEnter = Eventhandler;
    onCollisionEnter();
    
}
