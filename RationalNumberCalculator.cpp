#include <iostream>
#include "RationalNumber.h"
using namespace std;
int main()
{
	int a, b, c, d;
	char sign, temp;
	while (1)
	{
		system("cls");
		cout << "输入算式：";
		cin >> a >> temp >> b >> sign >> c >> temp >> d;
		RationalNumber num1(a, b);
		RationalNumber num2(c, d);
		RationalNumber ans(1, 1);
		switch (sign)
		{
		case '+':ans = num1 + num2; break;
		case '-':ans = num1 - num2; break;
		case '*':ans = num1 * num2; break;
		case '/':ans = num1 / num2; break;
		}
		cout << "答案为：";
		ans.print();
		cout << "\n\n按Enter重置";
		cin.get();
		cin.get();
	}
	return 0;
}
