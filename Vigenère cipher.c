#include<string.h>
#include<stdio.h>
int main()
{
	char ciphertext[100] = { 0 };
	char plaintext[] = "jinanuniversityisagreatuniversity";
	char key[50] = "bcid";                       /* ѧ�ź���λ2394��Ӧbcid*/
	int temp1, temp2;
	char cipher[100][100];                     /*��ά��������ĸ�������ά����*/
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
	printf("����Ϊ��%s\n", plaintext);
	printf("��ԿΪ��%s\n", key);
	char buffer[201];
	for (i = 0; i <= 3; i++) {                    /*������Կ�ַ���*/
		strcpy_s(buffer,100, key);
		strncat_s(key,100,buffer,100);
	}
	for (i = 0; i <= 34; i++) {        /*��ά��������ĸ���ҵ���Ӧ����*/
		temp1 = plaintext[i]-97;
		temp2 = key[i]-97;
		ciphertext[i]= cipher[temp1][temp2];
	}
	printf("����Ϊ��%s", ciphertext);
	return 0;
}
			
			
			