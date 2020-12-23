#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b) //快速排序函数所需的比较函数
{
	int* p1 = (int*)a;
	int* p2 = (int*)b;
	return *p2 - *p1;
}
FILE* create() {         //新建文件
	FILE* fp;
	char filename[] = "stu_sort.txt";
	fopen_s(&fp, filename, "w");
	if (fp == NULL) {   //打开失败应对措施
		printf("打开失败。");
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
	if (fp == NULL) {   //打开失败应对措施
		printf("打开失败。");
		exit(0);
	}
	for (int i=0; i < 5; i++) {
		fscanf_s(fp, "学生%d:%d", &buffer[0],&buffer[1]);
		while (fgetc(fp) != ',') {}       //将平均成绩前的所有字符全部读取
		fscanf_s(fp,"%d", &score[i]);     //读取平均成绩至score数组
		fgetc(fp);                        //读取\n
	}
	fclose(fp);
	qsort(score, 5, sizeof(int), compare); //快速排序函数
	fp = create();
	fprintf(fp, "排序后平均成绩为：%d %d %d %d %d", score[0], score[1], score[2], score[3], score[4]);
	return 0;
}