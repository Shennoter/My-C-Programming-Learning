#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) //��������������ıȽϺ���
{
	int* p1 = (int*)a;
	int* p2 = (int*)b;
	return *p2 - *p1;
}
FILE* create() {         //�½��ļ�
	FILE* fp;
	char filename[] = "stu_sort.txt";
	fopen_s(&fp, filename, "w");
	if (fp == NULL) {   //��ʧ��Ӧ�Դ�ʩ
		printf("��ʧ�ܡ�");
		exit(0);
	}
	return fp;
}
int main() {
	FILE* create();
	int compare(const void* elem1, const void* elem2);
	FILE* fp;
	char filename[] = "stud.txt";
	int score[5],buffer[2];
	fopen_s(&fp, filename, "r");
	if (fp == NULL) {   //��ʧ��Ӧ�Դ�ʩ
		printf("��ʧ�ܡ�");
		exit(0);
	}
	for (int i=0; i < 5; i++) {
		fscanf_s(fp, "ѧ��%d:%d", &buffer[0],&buffer[1]);
		while (fgetc(fp) != ',') {}       //��ƽ���ɼ�ǰ�������ַ�ȫ����ȡ
		fscanf_s(fp,"%d", &score[i]);     //��ȡƽ���ɼ���score����
		fgetc(fp);                        //��ȡ\n
	}
	fclose(fp);
	qsort(score, 5, sizeof(int), compare); //����������
	fp = create();
	fprintf(fp, "�����ƽ���ɼ�Ϊ��%d %d %d %d %d", score[0], score[1], score[2], score[3], score[4]);
	return 0;
}