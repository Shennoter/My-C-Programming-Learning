#include<stdio.h>
int sort(int* p) {
	int i, j, temp;
	for (i = 0; i <= 2; i++) {
		for (j = i+1; j <= 2; j++) {
			if (*(p+i) > *(p+j)) {
				temp = *(p+i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}
int main() {
	int sort(int* p);
	int arr[3];
	int *p;
	p = &arr;
	scanf_s("%d %d %d", &arr[0],&arr[1],&arr[2]);
	sort(p);
	printf("%d %d %d", *p, *(p + 1), *(p + 2));
	return 0;
}