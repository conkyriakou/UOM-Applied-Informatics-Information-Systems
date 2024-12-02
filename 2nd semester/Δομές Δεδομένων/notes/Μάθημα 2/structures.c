#include <stdio.h>

typedef struct {
	int day;
	int month;
	int year;
} date ;

int main(void)
{
	date birthday;
	birthday.day = 31;
	birthday.month = 3;
	birthday.year = 1998;
	printf("My birthday is on %d/%d/%d.\n", birthday.day, birthday.month, birthday.year);
	
	date birthday2;
	birthday2.day = 20;
	birthday2.month = 9;
	birthday2.year = 2004;
	printf("Konstantina birthday is on %d/%d/%d.\n", birthday2.day, birthday2.month, birthday2.year);
	
	date* birthday3;
	birthday3 = (date *) malloc(sizeof(date));
	birthday3->day = 20;
	birthday3->month = 9;
	birthday3->year = 2001;
	printf("Andrea birthday is on %d/%d/%d.\n", birthday3->day, birthday3->month, birthday3->year);
	
	free(birthday3);
	return 0;
}



