// February programming challenge
//   -> Day 24 - Fibonacci
//   -> Implement a program to generate the first terms of the Fibonacci sequence up to a given number

#include <stdio.h>

int main() {
	unsigned long num_asked=0;
	printf("Write the nth one you want : ");
	scanf("%lu", &num_asked);

	unsigned long num_one=0;
	unsigned long num_two=1;
	printf("%lu %lu ", num_one, num_two);

	for (int i=0; i<num_asked-2; i++) {
		unsigned long total=num_one+num_two;
		num_one=num_two;
		num_two=total;
		printf("%lu ", total);
	}
	return 0;
}
