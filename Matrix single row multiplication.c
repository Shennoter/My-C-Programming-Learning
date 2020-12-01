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
	void mulp1(int(*p)[5], int l, int k);   //第r行元素乘以k
	void mulp2(int* p, int l, int k);
	for (int i = 0; i < 20; i++) {          //随机生成矩阵
		*(p + i) = rand() % 10;
	}
	printf("原矩阵为：\n");
	for (int i = 0; i < 20; i++) {
		printf("%3d", *(p + i));
		if ((i + 1) % 5 == 0)printf("\n");
	}
	printf("\n");
	printf("使用mulp1--a\n使用mulp2--b\n");
	char key;
	key = getchar();
	printf("输入行数:");
	int r, k;
	scanf_s("%d", &r);
	printf("输入乘数:");
	scanf_s("%d", &k);
	if (key == 'a') {
		mulp1(matrix, r, k);
		printf("mulp1输出结果：\n");
		for (int i = 0; i < 20; i++) {
			printf("%3d", *(p + i));
			if ((i + 1) % 5 == 0)printf("\n");
		}
	}
	if (key == 'b') {
		mulp2(matrix[0], r, k);
		printf("mulp2输出结果：\n");
		for (int i = 0; i < 20; i++) {
			printf("%3d", *(p + i));
			if ((i + 1) % 5 == 0)printf("\n");
		}
	}
	return 0;
}