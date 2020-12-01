#include<stdio.h>
#include<string.h>
int character = 0, number = 0, space = 0;
void count(char* arr) {
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		if (64<=*(arr+i)&&90>=*(arr+i) || 97 <= *(arr + i) &&122 >= *(arr + i)) {
			character += 1;
		}
		else if (48 <= *(arr + i) && 57 >= *(arr + i)) {
			number += 1;
		}
		else if (*(arr + i) == ' ') {
			space += 1;
		}
	}
}
int main() {
	void count(arr);
	char arr[50];
	gets(arr);
	count(arr);
	printf("这段话的字母有%d个，数字有%d个，空格有%d个", character, number, space);
	return 0;
}