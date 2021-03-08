#include <iostream>
typedef int* Triplet;
using namespace std;
int InitTriplet(Triplet& T, int v1, int v2, int v3)//��ʼ����Ԫ��
{
	T = new int[3];
	T[0] = v1;
	T[1] = v2;
	T[2] = v3;
	return 1;
}
int DestroyTriplet(Triplet& T)//ɾ����Ԫ��
{
	delete[]T;
	T = NULL;
	return 1;
}
int Get(Triplet T, int i, int& e)//��ȡ��Ԫ���е�i��Ԫ��
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
int Put(Triplet& T, int i, int e)//����Ԫ���е�i��Ԫ����Ϊe
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
int IsAscending(Triplet T)//�ж���Ԫ��Ԫ���Ƿ�Ϊ��������
{
	return(T[0] <= T[1]) && (T[1] <= T[2]);
}
int IsDescending(Triplet T)//�ж���Ԫ��Ԫ���Ƿ�Ϊ����������
{
	return(T[0] >= T[1]) && (T[1] >= T[2]);
}
int Max(Triplet T, int& e)//��ȡ��Ԫ�������Ԫ��
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
int Min(Triplet T, int& e)//��ȡ��Ԫ������СԪ��
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
	cout << "����InitTriplet" << endl;
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	cout << "����DestroyTriplet" << endl;
	DestroyTriplet(T);
	if (T)
	{
		cout << "��Ԫ�����" << endl << endl;
	}
	else
	{
		cout << "��Ԫ�鲻����" << endl << endl;
	}
	InitTriplet(T, 12, 53, 68);
	cout << "����Get(T,1,e)" << endl;
	int e = 0;
	Get(T, 1, e);
	cout << e << endl << endl;
	cout << "����Put(T,1,20)" << endl;
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	Put(T, 1, 20);
	cout << "Triplet T(" << T[0] << "," << T[1] << "," << T[2] << ")" << endl << endl;
	cout << "����IsAscending" << endl;
	cout << IsAscending(T) << endl << endl;
	cout << "����IsDescending" << endl;
	cout << IsDescending(T) << endl << endl;
	cout << "����Max" << endl;
	Max(T, e);
	cout << e << endl << endl;
	cout << "����Min" << endl;
	Min(T, e);
	cout << e << endl << endl;
	cin.get();
	return 0;
}