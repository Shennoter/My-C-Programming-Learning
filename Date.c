#include<stdio.h>
void format1(int mm, int dd) {
	char* months[] = { "January","Feburary","March","April","May","June","July","August","September","October","November","December" };
	printf("%s %d",months[mm-1],dd);
}
void format2(int mm, int dd) {
	printf("%d/%d", mm, dd);
}
void pridate(int mm, int dd, int move, void (*pfunc)(int, int)) {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	dd += move;
	while (dd > days[mm - 1]) {
		dd -= days[mm - 1];
		mm = mm % 12 + 1;
	}
	(*pfunc)(mm, dd);
}

int main() {
	void format1(int mm, int dd);
	void format2(int mm, int dd);
	void pridate(int mm, int dd, int move, void (*pfunc)(int, int));
	int mdays(int mm);
	int mm, dd, key,move;
	printf("��������:");
	scanf_s("%d %d", &mm, &dd);
	printf("����������ڣ�");
	scanf_s("%d", &move);
	printf("ѡ�������ʽ��\n1����mm dd\n2����mm/dd\n");
	scanf_s("%d", &key);
	printf("ת����Ϊ��");
	if (key == 1) {
		pridate(mm, dd,move,format1);
	}
	else if (key == 2) {
		pridate(mm, dd,move,format2);
	}
	return 0;
}