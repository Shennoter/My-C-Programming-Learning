#include<stdio.h>
#include<stdlib.h>
void mulp1(int(*p)[5], int r, int k) {
	for (int i = 0; i < 5; i++) {
		*(*(p + (r - 1)) + i) *= k;
	}
}
void mulp2(int* p, int r, int k) {
	for (int i = 0; i < 5; i++) {
		*(p + (r - 1) * 5 + i) *= k;
	}
}
int main() {
	int matrix[4][5];
	int* p = matrix;
	void mulp1(int(*p)[5], int l, int k);   //��r��Ԫ�س���k
	void mulp2(int* p, int l, int k);
	for (int i = 0; i < 20; i++) {          //������ɾ���
		*(p + i) = rand() % 10;
	}
	printf("ԭ����Ϊ��\n");
	for (int i = 0; i < 20; i++) {
		printf("%3d", *(p + i));
		if ((i + 1) % 5 == 0)printf("\n");
	}
	printf("\n");
	printf("ʹ��mulp1--a\nʹ��mulp2--b\n");
	char key;
	key = getchar();
	printf("��������:");
	int r, k;
	scanf_s("%d", &r);
	printf("�������:");
	scanf_s("%d", &k);
	if (key == 'a') {
		mulp1(matrix, r, k);
		printf("mulp1��������\n");
		for (int i = 0; i < 20; i++) {
			printf("%3d", *(p + i));
			if ((i + 1) % 5 == 0)printf("\n");
		}
	}
	if (key == 'b') {
		mulp2(matrix[0], r, k);
		printf("mulp2��������\n");
		for (int i = 0; i < 20; i++) {
			printf("%3d", *(p + i));
			if ((i + 1) % 5 == 0)printf("\n");
		}
	}
	return 0;
}