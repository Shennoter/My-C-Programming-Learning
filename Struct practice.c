#include<stdio.h>
#include<string.h>
char* months[] = { "January","Feburary","March","April","May","June","July","August","September","October","November","December" };
struct Date {
	int syear;
	int smonth;
	int sday;
	};
struct Date date;
void priDate(struct Date* Date) {
	printf("%s %d %d", months[Date->smonth], Date->sday, Date->syear);
}
struct Date calDate(int year, int day) {
	int month=0;
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapdays[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		while (day > leapdays[month]) {
			day -= leapdays[month];
				month = month % 12 + 1;
		}
	}
	else {
		while (day > days[month]) {
			day -= days[month];
			month = month % 12 + 1;
		}
	}
	struct Date date;
	date.syear = year;
	date.sday = day;
	date.smonth = month;
	return date;
}
int minusDate(struct Date* pDate) {
	int result = 0, day1 = 0,day2=0, month = pDate->smonth;
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapdays[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	while (month>0) {             //计算这个月前面的月份加起来的天数day1
		month = month % 12 - 1;
		day1 += leapdays[month];
	}
	day2 = day1;        //day2是day1加上两个年份相差的天数
	if (pDate->syear > 2018) {        //求出day2
		for (int i = pDate->syear; i > 2018; --i) {
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
				day2 += 366;
			}
			else day2 += 365;
		}
		result = day2 + pDate->sday - 72;
	}
	else if (pDate->syear == 2018) {
		result = day2 + pDate->sday - 72;
	}
	else if (pDate->syear < 2018) {
		for (int i = 2017; i > pDate->syear; --i) {
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
				day2 += 366;
			}
			else day2 += 365;
		}
		result = 365-(day1 + pDate->sday) +(day2-day1)+ 72;
	}
	return result;
}
int main() {
	void priDate(struct Date*);
	struct Date calDate(int year, int day);
	int minusDate(struct Date* pDate);
	int cyear, cday;
	struct Date date = { 2018,2,12 };
	struct Date* pDate = &date;
	printf("原始日期为：");
	priDate(pDate);
	printf("\n输入年份和天数：");
	scanf_s("%d %d",&cyear,&cday);
	*pDate=calDate(cyear,cday);
	printf("%d年第%d天的日期是：", cyear, cday);
	priDate(pDate);
	printf("\n与原始日期相差%d天",minusDate(pDate));
	return 0;
}