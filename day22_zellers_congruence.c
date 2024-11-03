// February programming challenge
//   -> Day 22 - Zeller's congruence
//   -> Develop a program that determines the day following a given date using the rules of the Gregorian calendar

#include <stdio.h>

int main() {
	unsigned day, month, year;

	printf("Write the date separate by a '/' : ");
	scanf("%u/%u/%u", &day, &month, &year);

    if (month<3) {
        month+=12;
        year--;
    }
    unsigned year_century=year%100;
    unsigned century=year/100;

	unsigned result=(day + ((13 * (month + 1))/5) + year_century + (year_century/4) + (century/4) + (5*century)) % 7;

	switch (result) {
		case 0: printf("This is a Saturday !"); break;
		case 1: printf("This is a Sunday !"); break;
		case 2: printf("This is a Monday !"); break;
		case 3: printf("This is a Tuesday !"); break;
		case 4: printf("This is a Wednesday !"); break;
		case 5: printf("This is a Thursday !"); break;
		case 6: printf("This is a Friday !"); break;
		default: printf("Error..."); return 1;
	}
    return 0;
}
