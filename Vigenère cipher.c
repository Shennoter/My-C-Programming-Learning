#include<string.h>
#include<stdio.h>
int main()
{
	char ciphertext[100] = { 0 };
	char plaintext[] = "jinanuniversityisagreatuniversity";
	char key[50] = "bcid";                       /* 学号后四位2394对应bcid*/
	int temp1, temp2;
	char cipher[100][100];                     /*将维吉尼亚字母表输入二维数组*/
	int i = 0, j = 0, a = 0, b = 0;
	for (; i <= 25; i++, a++) {
		for (j = 0; j <= 25; j++, b++) {
			cipher[i][j] = 'a' + a + b;
			if (a + b >= 25) {
				a = -1;
				b = 0;
			}
		}
	}
	printf("明文为：%s\n", plaintext);
	printf("密钥为：%s\n", key);
	char buffer[201];
	for (i = 0; i <= 3; i++) {                    /*扩增密钥字符串*/
		strcpy_s(buffer,100, key);
		strncat_s(key,100,buffer,100);
	}
	for (i = 0; i <= 34; i++) {        /*在维吉尼亚字母表找到对应密文*/
		temp1 = plaintext[i]-97;
		temp2 = key[i]-97;
		ciphertext[i]= cipher[temp1][temp2];
	}
	printf("密文为：%s", ciphertext);
	return 0;
}
			
			
			