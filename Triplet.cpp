#include <iostream>
typedef int* Triplet;
using namespace std;
int InitTriplet(Triplet& T, int v1, int v2, int v3)//初始化三元组
{
	T = new int[3];
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return 1;
}
int DestroyTriplet(Triplet& T)//删除三元组
{
	delete[]T;
	T = NULL;
	return 1;
}
int Get(Triplet T, int i, int& e)//获取三元组中第i个元素
{
	if (i < 1 || i>3)
	{
		e = 0;
		cout << "ERROR" << endl;
		return 0;
	}
	e = T[i - 1];
	return 1;
}
int Put(Triplet& T, int i, int e)//将三元组中第i个元素设为e
{
	if (i < 1 || i>3)
	{
		e = 0;
		cout << "ERROR" << endl;
		return 0;
	}
	T[i - 1] = e;
	return 1;
}
int IsAscending(Triplet T)//判断三元组元素是否为升序排列
{
	return(T[0] <= T[1]) && (T[1] <= T[2]);
}
int IsDescending(Triplet T)//判断三元组元素是否为降序序排列
{
	return(T[0] >= T[1]) && (T[1] >= T[2]);
}
int Max(Triplet T, int& e)//获取三元组中最大元素
{
	e = T[0];
	for (int i = 0; i < 2; i++)
	{
		if (T[i] <= T[i + 1])
		{
			e = T[i + 1];
		}
	}
	return 1;
}
int Min(Triplet T, int& e)//获取三元组中最小元素
{
	e = T[0];
	for (int i = 0; i < 2; i++)
	{
		if (T[i] >= T[i + 1])
		{
			e = T[i + 1];
		}
	}
	return 1;
}
int main()
{
	int InitTriplet(Triplet & T, int v1, int v2, int v3);
	int DestroyTriplet(Triplet & T);
	int Get(Triplet T, int i, int& e);
	int Put(Triplet & T, int i, int e);
	int IsAscending(Triplet T);
	int IsDescending(Triplet T);
	int Max(Triplet T, int& e);
	int Min(Triplet T, int& e);
	Triplet T;
	InitTriplet(T, 12, 53, 68);
	cout << "测试InitTriplet" << endl;
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	cout << "测试DestroyTriplet" << endl;
	DestroyTriplet(T);
	if (T)
	{
		cout << "三元组存在" << endl << endl;
	}
	else
	{
		cout << "三元组不存在" << endl << endl;
	}
	InitTriplet(T, 12, 53, 68);
	cout << "测试Get(T,1,e)" << endl;
	int e = 0;
	Get(T, 1, e);
	cout << e << endl << endl;
	cout << "测试Put(T,1,20)" << endl;
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	Put(T, 1, 20);
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	cout << "测试IsAscending" << endl;
	cout << IsAscending(T) << endl << endl;
	cout << "测试IsDescending" << endl;
	cout << IsDescending(T) << endl << endl;
	cout << "测试Max" << endl;
	Max(T, e);
	cout << e << endl << endl;
	cout << "测试Min" << endl;
	Min(T, e);
	cout << e << endl << endl;
	cin.get();
	return 0;
}