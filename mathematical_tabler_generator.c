// February programming challenge
//   -> Day 12 - Mathematical table generation
//   -> Write a program that displays the multiplication, addition, subtraction and division tables as requested

#include <stdio.h>

int main() {
	char request;
	printf("Write +, -, / or * : ");
	scanf("%c", &request);
	float float_result=0.0;

	switch (request) {
		case '+':
			for (int i=1; i<10; i++) {
				for (int j=0; j<10; j++) {
					int result=i+j;
					printf("%d + %d = %d\n", i, j, result);
				}
				printf("\n");
			}
			break;

		case '-':
			for (int i=1; i<10; i++) {
				for (int j=0; j<10; j++) {
					int result=i-j;
					printf("%d - %d = %d\n", i, j, result);
				}
				printf("\n");
			}
			break;
		case '/':
			for (int i=1; i<10; i++) {
				for (int j=1; j<10; j++) {
					float_result=(float)i/j;
					printf("%d / %d = %f\n", i, j, float_result);
				}
				printf("\n");
			}
			break;
		case '*':
			for (int i=1; i<10; i++) {
				for (int j=0; j<10; j++) {
					int result=i*j;
					printf("%d * %d = %d\n", i, j, result);
				}
				printf("\n");
			}
			break;
	}

}
