// February programming challenge
//   -> Day 11 - Factorial calculation
//   -> Write a recursive function to calculate the factorial of a number

#include <stdio.h>

int main() {
    int n;
    printf("The number whose factorial you want to calculate : ");
    scanf("%d", &n);

    int result=n;

    if (n==0) {
        result=1;
    } else {
        for (int i=1; i<n; i++) {
            result=result*(n-i);
        }
    }
    printf("The factorial : %d", result);
    return 0;
}
