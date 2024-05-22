#include <iostream>
#include <chrono> //시간
#include <thread> //sleep

using namespace std;

int main()
{
	int count = 0;

	chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	while (count<100)
	{
		
		prev_end = end;
		end = chrono::steady_clock::now();
		count++;
		cout << "카운트 : " << count << endl;

		chrono::steady_clock::duration diff = end - prev_end;
		int duration_ms = chrono::duration_cast<chrono::milliseconds>(diff).count();
		
		if(1000-duration_ms>0)
			this_thread::sleep_for(chrono::milliseconds(1000 - duration_ms));

		//count++;
		//cout << "카운트 : " << count << endl;

		//start = end;
		//end = chrono::steady_clock::now();
		//chrono::steady_clock::duration diff = end - start; // 차이

		//int duration_ms = chrono::duration_cast<chrono::milliseconds>(diff).count();
		//
		//if(duration_ms < 1000)
		//	this_thread::sleep_for(chrono::milliseconds(1000 - duration_ms));
	}
}