// February programming challenge
//   -> Day 19 - Calculating GCD and LCM
//   -> Implement an algorithm to calculate the GCD and/or LCM of two numbers

#include <stdio.h>

int gcd(int a, int b) {
	while (b!=0) {
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int lcm(int a, int b, int result_gcd) {
	if (result_gcd==0) return 0;
	return (a*b)/result_gcd;
}
int main() {
	int a=0;
	int b=0;
	printf("First number : ");
	scanf("%d", &a);

	printf("Second number : ");
	scanf("%d", &b);

	if (a==0 && b==0) {
		printf("Error : please don't enter two 0");
		return 1;
	} else if (a == 0 || b == 0) {
	    printf("Warning: One of the numbers is zero. GCD and LCM are not defined.\n");
	} else {
		int result_gcd=gcd(a, b);
		printf("GCD(%d, %d) : %d\n", a, b, result_gcd);

		int result_lcm=lcm(a, b, result_gcd);
		printf("LCM(%d, %d) : %d\n", a, b, result_lcm);
	}
	return 0;
}
