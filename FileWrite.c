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
	if (fp == NULL) {   //打开失败应对措施
		printf("打开失败。");
		exit(0);
	}
	return fp;
}
void input(int a){            //从键盘输入数据
	
	printf("输入第%d个学生的学号：", a+1);
	scanf_s("%d", &student[a].num);
	(void)getchar();
	printf("姓名:");
	gets_s(student[a].name,20);
	printf("三门课成绩：");
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
	for (int i = 0; i < 5; i++) {      //求平均成绩
		for (int j = 0; j < 3; j++) {
			temp += student[i].score[j];
		}
		average[i] = temp / 3;
		temp = 0;
	}
	for (int i = 0; i < 5; i++) {    //写入文件
		fprintf(fp, "学生%d:%d %s %d %d %d,%d\n", i+1, student[i].num, student[i].name, student[i].score[0], student[i].score[1], student[i].score[2], average[i]);
		//fwrite(&student[i], sizeof(struct stu), 1, fp);
	}
	fclose(fp);
	return 0;
}