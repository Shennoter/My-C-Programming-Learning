#include<stdio.h>
#include<stdlib.h>
float score[4][5] = { 58,26,74,83,97,86,87,88,85,89,13,47,32,61,74,68,98,96,97,95};
float avgCourse(float(*pScore)[5], int studentNum, int courseIdx) {    //返回第courseIdx门课的平均成绩
	float score=0;
	for (int i = 0; i < 5; i++) {
		score += *(*(pScore + i) + (courseIdx - 1));
	}
	return score / studentNum;
}
float avgStudent(float* pStuScore, int courseNum) {     //返回某一学生的平均成绩
	float score=0;
	for (int i = 0; i < 5; i++) {
		score += *(pStuScore + i);
	}
	return score / courseNum;
}
float lowbdStudent(float* pStuScore, int courseNum) {   //返回某一学生的最低成绩
	float min=*(pStuScore+ courseNum-1);
	for (int i = 0; i < courseNum; i++) {
		if (*(pStuScore+i) < min) {
			min = *(pStuScore + i);
		 }
	}
	return min;
}
int failNumStudent(float* pStuScore, int courseNum) {   //返回某一学生的不及格成绩个数
	int fail = 0;
	for (int i = 0; i < courseNum; i++) {
		if (*(pStuScore + i) < 60) {
			fail += 1;
		}
	}
	return fail;
}
void priScore(float(*pScore)[5], int studentIdx) {      //输出第studentIdx个学生的成绩
	for (int i = 0; i < 5; i++) {
		printf("%8.2f", *(*(pScore + studentIdx) + i));
	}
}
void func1(void) {          //功能一：求某门课程平均分
	int courseIdx;
	printf("输入课程序号：");
	scanf_s("%d", &courseIdx);
	printf("第%d门课的平均成绩为：%.2f",courseIdx,avgCourse(score, 4, courseIdx));
}
void func2(void) {          //功能二：找出两门以上课程不及格的学生
	float* p=score[0];
	printf("两门以上课程不及格的学生有：\n");
	for (int i = 0; i < 4; i++) {
		if (failNumStudent(score[i], 5) >= 2) {
			printf("%d号学生：", i + 1);
			priScore(score, i);
			printf("\n");
		}
	}
} 
void func3(void) {          //功能三：找出平均成绩>=90或每门课成绩都>=85的学生
	printf("平均成绩>=90或每门课成绩都>=85的学生为：\n");
	float* p3 = score[0];
	for (int i = 0; i < 4; i++) {
		if (avgStudent(p3+i*5, 5) >= 90) {
			printf("%d号学生：", i + 1);
			priScore(score, i);
			printf("\n");
		}
		else if (lowbdStudent(p3+ i*5, 5) >= 85) {
			printf("%d号学生：", i + 1);
			priScore(score, i);
			printf("\n");
		}
	}
}
int main() {
	float avgCourse(float(*pScore)[5], int studentNum, int courseIdx);
	float avgStudent(float* pStuScore, int courseNum);                  
	float lowbdStudent(float* pStuScore, int courseNum);                
	int failNumStudent(float* pStuScore, int courseNum);                
	void priScore(float(*pScore)[5], int studentIdx);                   
	void func1(void);  
	void func2(void);  
	void func3(void);  
	float (*p1)[5] = score;
	for (int i = 0,k=1; i <= 3; i++,k++) {
		printf("第%d个学生的成绩分别为：", k);
		for (int j = 0; j <= 4; j++) {
			printf("%8.2f", *(*(p1+i)+j));
		}
		printf("\n");
	}
	printf("————————————————————————————————");
	//菜单区
	printf("\nA——求某门课程平均分\nB——找出两门以上课程不及格的学生\nC——找出平均成绩>90或总成绩>85的学生\n");
	char key;
	key = getchar();
	if (key == 'a' || key == 'A') {
		func1();
	}
	if (key == 'b' || key == 'B') {
		func2();
	}
	if (key == 'c' || key == 'C') {
		func3();
	}
	return 0;
}