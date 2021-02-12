#include<iostream>
#include<time.h>
using namespace std;
int main() {
	int len,fun,mode;
	srand((int)time(0));
	cout << "1 -- 混合" << endl << "2 -- 纯数字" << endl;
	cin >> mode;
	cout << "输入字符串长度：";
	cin >> len;
	string arr(len, '0');
	if (mode == 1) {
		for (int i = 0; i < len; i++) {
			fun = rand() % 3 + 1;
			switch (fun) {
			case 1:arr[i] = '0' + rand() % 10; break;
			case 2:arr[i] = 'A' + rand() % 26; break;
			case 3:arr[i] = 'a' + rand() % 26; break;
			}
		}
	}
	else{
		for (int i = 0; i < len; i++) {
			arr[i] = '0' + rand() % 10;
		}
	}
	cout << arr << endl << endl;
	cout << "按回车键退出";
	cin.get();
	cin.get();
	return 0;
}
