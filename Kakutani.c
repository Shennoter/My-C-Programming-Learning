#include<stdio.h>
void kakutani(int);
int step = 0,num;
int main() {
	printf("�ǹȲ���\n����һ����:");
	scanf_s("%d", &num);
	kakutani(num);
	printf("ִ�еĲ���Ϊ��%d",step);
	return 0;
}
void kakutani(int a) {             //�ǹȵ�������Ϊkakutani
	if (a != 1 && a % 2 == 0) {
		a = a / 2;
		step += 1;
		kakutani(a);
	}
	else if (a != 1 && a % 2 != 0) {
		a = a * 3 + 1;
		step += 1;
		kakutani(a);
	}
	else if (a == 1) {
		printf("�������,");
	}
}