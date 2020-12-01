#include<stdio.h>
void kakutani(int);
int step = 0,num;
int main() {
	printf("角谷猜想\n输入一个数:");
	scanf_s("%d", &num);
	kakutani(num);
	printf("执行的步数为：%d",step);
	return 0;
}
void kakutani(int a) {             //角谷的罗马音为kakutani
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
		printf("计算结束,");
	}
}