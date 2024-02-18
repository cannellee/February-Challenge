// February programming challenge
//   -> Day 18 - Credit card validation
//   -> Check the validity of a credit card number using the Luhn algorithm

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	unsigned long number=0;
	int result=0;
	char control_number;

	printf("Enter a number and a 'x' : ");
	scanf("%lu %c", &number, &control_number);

	if (!isdigit(control_number) && control_number!='x') {
		printf("Invalid input.\n");
		return 1;
	} else {
		char cdc_number[50];
		sprintf(cdc_number, "%lu", number);
		int count=strlen(cdc_number);

		if (isdigit(control_number)) {
			count--;
		}

		for (int i=count-1; i>=0; i--) {
			int digit=cdc_number[i]-'0';
			if ((count-i)%2==0) {
				digit*=2;
				if (digit>9) {
					digit=(digit%10)+1;
				}
			}
			result+=digit;
		}

		if (result%10==0) {
			printf("Your number is valid.\n");
		} else if (control_number=='x') {
			int x=10-(result%10);
			printf("Your number is valid with x=%d.\n", x);
		} else {
			printf("Your number is invalid.\n");
		}
	}
	return 0;
}
