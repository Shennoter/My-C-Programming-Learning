#include<stdio.h>
int main() {
	int a[4][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };
	int* p1=a;  
	int(*p2)[5] = &a;
	printf("p1�������a��");
	for (int i=0; i <=19; i++) {
		if (i % 5 == 0)printf("\n");
		printf("%3d",*p1+i);
	}
	printf("\n");
	printf("\np2�������a��\n");
	for (int i=0; i<=19; i++) {
		printf("%3d", *(*p2+i));
		if ((i+1) % 5 == 0)printf("\n");
	}
	printf("\np1�õ���a[2][2]������Ϊ%d����ַΪ%p", *p1+12, p1+12);
	printf("\np2�õ���a[2][2]������Ϊ%d����ַΪ%p", *(*(p2 + 2) + 2), *(p2 + 2) + 2);
	return 0;
}