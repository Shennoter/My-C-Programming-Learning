#include<stdio.h>
#include<stdlib.h>
float score[4][5] = { 58,26,74,83,97,86,87,88,85,89,13,47,32,61,74,68,98,96,97,95};
float avgCourse(float(*pScore)[5], int studentNum, int courseIdx) {    //���ص�courseIdx�ſε�ƽ���ɼ�
	float score=0;
	for (int i = 0; i < 5; i++) {
		score += *(*(pScore + i) + (courseIdx - 1));
	}
	return score / studentNum;
}
float avgStudent(float* pStuScore, int courseNum) {     //����ĳһѧ����ƽ���ɼ�
	float score=0;
	for (int i = 0; i < 5; i++) {
		score += *(pStuScore + i);
	}
	return score / courseNum;
}
float lowbdStudent(float* pStuScore, int courseNum) {   //����ĳһѧ������ͳɼ�
	float min=*(pStuScore+ courseNum-1);
	for (int i = 0; i < courseNum; i++) {
		if (*(pStuScore+i) < min) {
			min = *(pStuScore + i);
		 }
	}
	return min;
}
int failNumStudent(float* pStuScore, int courseNum) {   //����ĳһѧ���Ĳ�����ɼ�����
	int fail = 0;
	for (int i = 0; i < courseNum; i++) {
		if (*(pStuScore + i) < 60) {
			fail += 1;
		}
	}
	return fail;
}
void priScore(float(*pScore)[5], int studentIdx) {      //�����studentIdx��ѧ���ĳɼ�
	for (int i = 0; i < 5; i++) {
		printf("%8.2f", *(*(pScore + studentIdx) + i));
	}
}
void func1(void) {          //����һ����ĳ�ſγ�ƽ����
	int courseIdx;
	printf("����γ���ţ�");
	scanf_s("%d", &courseIdx);
	printf("��%d�ſε�ƽ���ɼ�Ϊ��%.2f",courseIdx,avgCourse(score, 4, courseIdx));
}
void func2(void) {          //���ܶ����ҳ��������Ͽγ̲������ѧ��
	float* p=score[0];
	printf("�������Ͽγ̲������ѧ���У�\n");
	for (int i = 0; i < 4; i++) {
		if (failNumStudent(score[i], 5) >= 2) {
			printf("%d��ѧ����", i + 1);
			priScore(score, i);
			printf("\n");
		}
	}
} 
void func3(void) {          //���������ҳ�ƽ���ɼ�>=90��ÿ�ſγɼ���>=85��ѧ��
	printf("ƽ���ɼ�>=90��ÿ�ſγɼ���>=85��ѧ��Ϊ��\n");
	float* p3 = score[0];
	for (int i = 0; i < 4; i++) {
		if (avgStudent(p3+i*5, 5) >= 90) {
			printf("%d��ѧ����", i + 1);
			priScore(score, i);
			printf("\n");
		}
		else if (lowbdStudent(p3+ i*5, 5) >= 85) {
			printf("%d��ѧ����", i + 1);
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
		printf("��%d��ѧ���ĳɼ��ֱ�Ϊ��", k);
		for (int j = 0; j <= 4; j++) {
			printf("%8.2f", *(*(p1+i)+j));
		}
		printf("\n");
	}
	printf("����������������������������������������������������������������");
	//�˵���
	printf("\nA������ĳ�ſγ�ƽ����\nB�����ҳ��������Ͽγ̲������ѧ��\nC�����ҳ�ƽ���ɼ�>90���ܳɼ�>85��ѧ��\n");
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