#include<stdio.h>
#include<stdlib.h>
struct stu {
	int num;
	char name[20];
	int score[3];
};
struct stu student[5];
FILE* create(){
	FILE* fp;
	char filename[] = "stud.txt";
	fopen_s(&fp, filename, "w");
	if (fp == NULL) {   //��ʧ��Ӧ�Դ�ʩ
		printf("��ʧ�ܡ�");
		exit(0);
	}
	return fp;
}
void input(int a){            //�Ӽ�����������
	
	printf("�����%d��ѧ����ѧ�ţ�", a+1);
	scanf_s("%d", &student[a].num);
	(void)getchar();
	printf("����:");
	gets_s(student[a].name,20);
	printf("���ſγɼ���");
	scanf_s("%d %d %d", &student[a].score[0], &student[a].score[1], &student[a].score[2]);
	printf("\n");
}
int main(){
	FILE* create(void);
	void input(int a);
	int average[5], temp = 0;
	FILE* fp;
	fp = create();
	for (int i = 0; i < 5; i++) {
		input(i);
	}
	for (int i = 0; i < 5; i++) {      //��ƽ���ɼ�
		for (int j = 0; j < 3; j++) {
			temp += student[i].score[j];
		}
		average[i] = temp / 3;
		temp = 0;
	}
	for (int i = 0; i < 5; i++) {    //д���ļ�
		fprintf(fp, "ѧ��%d:%d %s %d %d %d,%d\n", i+1, student[i].num, student[i].name, student[i].score[0], student[i].score[1], student[i].score[2], average[i]);
		//fwrite(&student[i], sizeof(struct stu), 1, fp);
	}
	fclose(fp);
	return 0;
}