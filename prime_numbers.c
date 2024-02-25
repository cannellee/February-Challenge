// February programming challenge
//   -> Day 25 - Prime numbers
//   -> Implement a program that generates a list of primes up to a given number

#include <stdio.h>
#include <math.h>

int main() {
	int choice;
	printf("Enter 1 to generate prime numbers, 2 if you want to know a specific number : ");
	scanf("%d", &choice);

	if (choice==1) {
		unsigned long rank=0;
		int count=1;
		printf("Enter the rank of prime numbers you want to generate : ");
		scanf("%lu", &rank);
		rank++;

		for (unsigned long i=2; count<rank; i++) {
			int is_prime=1;
			for (unsigned long j=2; j<=sqrt(i); j++) {
				if (i%j==0) {
					is_prime=0;
					break;
				}
			}
			if (is_prime) {
				printf("%lu ", i);
				count++;
			}
		}
		printf("\n");
	} else if (choice==2) {
		unsigned long number=0;
		printf("Enter the number : ");
		scanf("%lu", &number);

		if (number<2) {
			printf("No");
			break;
		}
		for (int i=2; i<sqrt(number)+1; i++) {
			if (number%i==0) {
				printf("No");
				break;
			}
		}
		printf("Yes");
	}
	return 0;
}
