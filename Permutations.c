#include<stdio.h>
#include<string.h>
void swap(char* a, char* b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void permutation(char* str,int k, int lenth) {
	if (k == lenth) {
		printf("%s\n", str);
	}
	else {
		for (int i = k; i <= lenth; i++) {
			swap(str + i, str + k);
			permutation(str,k+1, lenth);
			swap(str + i, str + k);
		}
	}
}
int main() {
	printf("输入字符串：\n");
	char str[50] = { 0 };
	gets(str);
	int lenth = strlen(str) - 1;
	printf("全排列结果为:\n");
	permutation(str, 0, lenth);
	return 0;
}