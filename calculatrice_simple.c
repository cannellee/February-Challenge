// February programming challenge
//   -> Day 1 - Simple calculator
//   -> Implement basics operations (+, -, *, /) for two numbers

#include <stdio.h>
#include <stdlib.h>

int main(){
	char equation[4];
	float result=0;
	printf("Equation of two numbers separate with a basic operation : ");
	fflush(stdout);
	scanf("%s", equation);
	switch (equation[1]) {
		case '+':
			result=(float)(equation[0]-'0')+(float)(equation[2]-'0');
			break;
		case '-':
			result=(float)(equation[0]-'0')-(float)(equation[2]-'0');
			break;
		case '*':
			result=(float)(equation[0]-'0')*(float)(equation[2]-'0');
			break;
		case '/':
			if (equation[2]!='0') {
				result=(float)(equation[0]-'0')/(float)(equation[2]-'0');
			} else {
				printf("You can't divide by 0 !\n");
			}
			break;
		default:
			printf("Please retry !");
			break;
	}
	printf("Result : %.2f", result);
	return 0;
}
