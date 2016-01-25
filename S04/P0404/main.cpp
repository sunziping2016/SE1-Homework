#include <stdio.h>

int main()
{
	int daysofmonth[][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	int year, month, days = -1, i, leap; // Note: month = real_month - 1
	scanf("%d", &year);
	for (i = 1998; i < year; ++i)
		days += (i % 4 == 0 && i % 100) || i % 400 == 0 ? 366 : 365;
	leap = (year % 4 == 0 && year % 100) || year % 400 == 0;
	for (month = 0; month < 12; ++month) {
		if ((days + 13 ) % 7 == 1)
			printf("%d-%02d-13\n", year, month + 1);
		days += daysofmonth[leap][month];
	}
	return 0;
}
