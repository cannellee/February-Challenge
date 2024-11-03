// February programming challenge
//   -> Day 17 - Degrees-radians conversions
//   -> Develop a program that converts angles between degrees and radians

#include <stdio.h>
#include <math.h>

int main() {
	char choice;
	int number;
	const double pi=M_PI;

	printf("Write D/d: degrees or R/r: radians for the unit of angle in which you are writing : ");
	scanf("%c", &choice);
	printf("Write the number : ");
	scanf("%d", &number);

	if (choice=='R' || choice=='r') {
		float degrees=number*(pi/180);
		printf("\nIn degrees : %.1f", degrees);
	} else if (choice=='D' || choice=='d') {
		float radians=number*(pi/180);
		printf("\nIn radians : %.1f", radians);
	} else {
		printf("Please enter a valid letter.");
		return 1;
	}

	return 0;
}
