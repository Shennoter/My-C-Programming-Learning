#include<stdio.h>
int main()
{
	printf("输入第一个数组的五个数：");
	int a[5], b[5],boo;
	scanf_s("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
	printf("输入第二个数组的五个数：");
	scanf_s("%d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4]);
	for (int i = 0; i <= 5; i++) {
		if (a[i] != b[i]) {
			boo = 0;
			break;
		}
		else if (a[i] == b[i]) {
			boo = 1;
		}
	}
	if (boo == 0) {
		printf("两数组不相等");
	}
	else if (boo == 1) {
		printf("两数组相等");
	}
	return 0;

}