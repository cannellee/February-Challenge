// February programming challenge
//   -> Day 23 - Perfect root
//   -> Implement an algorithm to calculate the integer square root of a given integer

#include <stdio.h>
#include <math.h>

int main() {
	float number=0;
	printf("Write the number to put at the root : ");
	scanf("%f", &number);
	float pow_number=pow(number, 0.5);
	int floor_number=floor(pow_number);
	if (pow_number==floor_number) {
	    printf("%g have a perfect root : %d.\n", number, floor_number);
	} else {
	    printf("This isn’t a perfect root.\n");
	}
    return 0;
}
