#include <iostream>
#include "RationalNumber.h"
using namespace std;
int main()
{
	int a, b, c, d, fun;
	while (1)
	{
		system("cls");
		cout << "�����һ����������";
		cin >> a >> b;
		RationalNumber num1(a, b);
		cout << "����ڶ�����������";
		cin >> c >> d;
		RationalNumber num2(c, d);
		cout << "ѡ�����㣺1--�ӷ�  2--����  3--�˷�  4--����" << endl;
		cin >> fun;
		RationalNumber ans(1, 1);
		switch (fun)
		{
		case 1:ans = num1 + num2; break;
		case 2:ans = num1 - num2; break;
		case 3:ans = num1 * num2; break;
		case 4:ans = num1 / num2; break;
		}
		cout << "��Ϊ��";
		ans.print();
		cout << "\n\n��Enter����";
		cin.get();
		cin.get();
	}
	return 0;
}