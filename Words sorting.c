#include<stdio.h>
#include<string.h>
char charget(char (*p)[8],int move) {            //��ȡ�����������������ĸ
	char character = { 0 };
	for (int i = 7; i >= 0; i--) {
		if (*(*p + i) != '\0') {
			character = *(*p + i - move);
			break;
		}
	}
	return character;
}
void swap(char(*p1)[8], char(*p2)[8]) {          //���������ַ�������
	char temp[8];
	strcpy_s(temp, strlen(*p1) + 1,*p1);
	strcpy_s(*p1, strlen(*p2) + 1, *p2);
	strcpy_s(*p2, strlen(temp) + 1,temp);
}
int main() {
	char charget(char (*p)[8],int move);
	void swap(char (*p1)[8], char (*p2)[8]);
	char words[10][8]= { "kyoma","mayuri","itaru","kurisu","suzuha","rukako","faris","moeka","maho","gakari" };
	char (*p)[8] = words;
	int k;
	printf("ԭ����Ϊ��");
	for (int i = 0; i < 10; i++) {
		printf("%s   ", words + i);
	}
	for (int i = 0; i < 10; i++) {                         //����ð������
		for (int j = i + 1; j < 10; j++) {
			k = 0;
			while (charget(p + i, k) == charget(p + j, k)) {
				k += 1;
			}
			if (charget(p + i, k) > charget(p + j, k)) {
				swap(p + i, p + j);
			}
			k = 0;
		}
	}
	printf("\n\n�����Ϊ��");
	for (int i = 0; i < 10; i++) {
		printf("%s   ", words + i);
	}
	return 0;
}