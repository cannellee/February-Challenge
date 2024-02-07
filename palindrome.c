// February programming challenge
//   -> Day 7 - Palindrome
//   -> Write a program to check whether a character string is a palindrome

#include <stdio.h>
#include <string.h>

int main() {
    char cdc[100];
    printf("Content : ");
    scanf("%s", cdc);

    for (int i=0; i<strlen(cdc)/2; i++) {
        if (cdc[i]!=cdc[strlen(cdc)-i-1]) {
        	printf("This word is not a palindrome !");
        	return 1;
        }
    }
    printf("This word is a palindrome !");
    return 0;
}
