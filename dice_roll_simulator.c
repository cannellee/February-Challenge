// February programming challenge
//   -> Day 29 - Simulated dice roll
//   -> Simulate a dice roll

#include <stdio.h>
#include <time.h>

int main() {
	srand(time(NULL));

	unsigned number=0;
	printf("How dice do you want : ");
	scanf("%d", &number);

	int count=0;

	for (int i=0; i<number; i++) {
		int dice=rand()%6;
		printf("Dice %d : %d\n", i+1, dice);
		count+=dice;
	}
	printf("Count : %d", count);
	return 0;
}
