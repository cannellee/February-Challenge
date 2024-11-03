// February programming challenge
//   -> Day 16 - Roman Numerals
//   -> Convert Roman numbers into Arabic numbers and vice versa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//1 - I || 5 - V || 10 - X || 50 - L || 100 - C || 500 - D || 1000 - M

int romanToArabic(char *roman) {
    char symbols[]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[]={1, 5, 10, 50, 100, 500, 1000};
    int result=0;
    int prev=0;

    for (int i=strlen(roman)-1; i>=0; i--) {
        int found=0;
        for (int j=0; j<sizeof(symbols); j++) {
            if (roman[i]==symbols[j]) {
                found=1;
                if (values[j]<prev) {
                    result-=values[j];
                } else {
                    result+=values[j];
                }
                prev=values[j];
                break;
            }
        }
        if (!found) {
            printf("Invalid Roman numeral: %c\n", roman[i]);
            return 1;
        }
    }

    return result;
}

void arabicToRoman(int number) {
    if (number<=0) {
        printf("Number out of range.\n");
        return;
    }

    int arabic[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i=0; i<sizeof(arabic)/sizeof(arabic[0]); i++) {
        while (number>=arabic[i]) {
            printf("%s", roman[i]);
            number-=arabic[i];
        }
    }
    printf("\n");
}

int main() {
    char request[100];
    printf("Your request : ");
    scanf("%s", request);

    if (isdigit(request[0])) {
        int number=atoi(request);
        printf("Result : ");
        arabicToRoman(number);
    } else {
        int result=romanToArabic(request);
        if (result!=-1) {
            printf("Result : %d\n", result);
        }
    }

    return 0;
}
