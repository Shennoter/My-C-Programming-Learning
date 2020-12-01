#include<stdio.h>
void extract(int* parr) {
	int count=0,k = 0;
	for (int i = 0, j = 12; i <= 5; i++) {
		if (*(parr + i) == 0) {
			count++;
		}
		else continue;
	}
	for(int a=0;a<=count;a++){
		for (int i = 0; i <= 12; i++) {
			if (*(parr + i) == 0) {
				*(parr + i) = *(parr + i + 1);
				for (int j = i; j <= 11; j++) {
					*(parr + j) = *(parr + j + 1);
				}
			}
		}
	}
	for (int k = 0; k <= count+1; k++) {
		*(parr + 12 - k) = 0;
	}
}
int main() {
	void extract(int* parr);
	int arr[13] = { 1,2,3,0,7,8,0,3,4,0,1,2,1 };
	int* parr = arr;
	printf("原数组为：");
	for (int i = 0; i <= 12; i++) {
		printf("%d", *(parr+i));
	}
	printf("\n");
	extract(parr);
	printf("处理后数组为：");
	for (int i = 0; i <= 12; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}