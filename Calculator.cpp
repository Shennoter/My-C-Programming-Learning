#include<iostream>
using namespace std;
int main()
{
	double num1 = 0.0, num2 = 0.0;
	char sign = 0;
	while (1)
	{
		system("cls");
		cin >> num1 >> sign >> num2;
		switch (sign)
		{
		case'+':
			cout << num1 + num2; break;
		case'-':
			cout << num1 - num2; break;
		case'*':
			cout << num1 * num2; break;
		case'/':
			if (num2 == 0)
			{
				cout << "��������Ϊ0";
				break;
			}
			cout << num1 / num2; break;
		}
		cout << "\n\n��Enter����";
		cin.get();
		cin.get();
	}
	return 0;
}