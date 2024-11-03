// February programming challenge
//   -> Day 2 - Random number generator
//   -> Generate a sequence of random numbers using the algorithm of your choice

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>

int main() {
	srand(time(NULL));
	printf("Guess the random number\nWrite q or Q if you want to stop ;)\nMax number : ");
	int max_number;
	scanf(" %d", &max_number);
	getchar();
	max_number+=1;

	while (1) {
		int random_number=rand()%max_number;
		char guess;
		printf("Enter your guess : ");
		scanf(" %c", &guess);

		if (tolower(guess)=='q') {
			printf("Bye bye");
			break;
		}

		if (!isdigit(guess) || guess<'0' || guess-'0'>=max_number) {
			printf("Please write a number into 0 and %d", max_number-1);
		}

		if (random_number != (guess-'0')) {
			printf("Retry\n");
		} else {
			printf("Exactly");
			break;
		}
	}
	return 0;
}
