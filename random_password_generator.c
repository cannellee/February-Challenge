// February programming challenge
//   -> Day 21 - Random password generator
//   -> Write a program that generates complex random passwords

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
    char possibility[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '[', ']', '{', '}', '|', ';', ':', ',', '.', '<', '>', '?'};

    unsigned length=0;
    printf("The length you want : ");
    scanf("%d", &length);

    char password[length+1];
    for (int i=0; i<length; i++) {
    	password[i]=possibility[rand()%90];
    }
    password[length]='\0';
    printf("Your password : %s", password);

    return 0;
}
