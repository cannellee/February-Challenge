// February programming challenge
//   -> Day 6 - Reverse Polish notation
//   -> Make a calculator that supports input in inverted Polish notation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
	char equation[MAX_SIZE];
	printf("Write an expression : ");
	fgets(equation, MAX_SIZE, stdin);
	equation[strcspn(equation, "\n")]='\0';
	char *punct_ptr=strpbrk(equation, "+-*/");

	if (punct_ptr!=NULL) {
		float numbers[MAX_SIZE];
		char operators[MAX_SIZE];
		int num_index=0;
		int op_index=0;
		char calculation[4];

		char *token=strtok(equation, " ");
		while (token!=NULL) {
			if (isdigit(*token)) {
				numbers[num_index++]=atof(token);
			} else if (ispunct(*token)){
				operators[op_index++]=*token;
			} else if (!isspace(*token)) {
				printf("Error: please write only numbers and operators in the equation");
				return 1;
			}
			token=strtok(NULL, " ");
		}
		calculation[3]='\0';

		if (num_index!=op_index+1) {
			printf("Error: please write the correct number of operators and numbers");
			return 1;
		} else {
			while (num_index!=1 && op_index!=0) {
				calculation[0]=(float)(numbers[num_index-2]);
				calculation[1]=operators[0];
				calculation[2]=(float)(numbers[num_index-1]);
				memmove(operators, operators+1, op_index-1);
				op_index--;

				switch (calculation[1]) {
					case '+':
						numbers[num_index-2]=calculation[0]+calculation[2];
						break;
					case '-':
						numbers[num_index-2]=calculation[0]-calculation[2];
						break;
					case '/':
						if (calculation[2]!=0) {
							numbers[num_index-2]=calculation[0]/calculation[2];
						} else {
							printf("Error: please don't divide by 0");
							return 1;
						}
						break;
					case '*':
						numbers[num_index-2]=calculation[0]*calculation[2];
						break;
					default:
						printf("Error: only +, -, / and * are accepted");
						break;
				}
				num_index--;
			}
			printf("Result : %f", numbers[0]);
		}
	} else {
		printf("Error: please write operators in the equation");
		return 1;
	}

	return 0;
}
