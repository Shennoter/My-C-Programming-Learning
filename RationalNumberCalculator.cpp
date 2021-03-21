#include <iostream>
#include "RationalNumber.h"
using namespace std;
int main()
{
	int a, b, c, d, fun;
	while (1)
	{
		system("cls");
		cout << "输入第一个有理数：";
		cin >> a >> b;
		RationalNumber num1(a, b);
		cout << "输入第二个有理数：";
		cin >> c >> d;
		RationalNumber num2(c, d);
		cout << "选择运算：1--加法  2--减法  3--乘法  4--除法" << endl;
		cin >> fun;
		RationalNumber ans(1, 1);
		switch (fun)
		{
		case 1:ans = num1 + num2; break;
		case 2:ans = num1 - num2; break;
		case 3:ans = num1 * num2; break;
		case 4:ans = num1 / num2; break;
		}
		cout << "答案为：";
		ans.print();
		cout << "\n\n按Enter重置";
		cin.get();
		cin.get();
	}
	return 0;
}