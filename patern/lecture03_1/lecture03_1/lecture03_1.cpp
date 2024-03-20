#include <iostream>
using namespace std;
/* stream = 연결통로 */
int main()
{
	int num = 0;
	cout << "게임이 실행됐습니다" << endl; /*endl = 엔터 */
	while (num != 9999)
	{
		cout << "내가 싫어하는 숫자를 써봐 : " << endl;
		cin >> num;
		cout << "왜그러니... 그 숫자가 아니야" << endl;
	}
	cout << "잘했어"<< num<<"이라는 숫자를 좋아하는구나 " << endl;
	return 0;
}