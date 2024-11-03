// February programming challenge
//   -> Day 4 - Combinations
//   -> Write a function that displays, in ascending order, all the numbers made up of three different digits

#include <stdio.h>

int main() {
    int number;
    for (int a=0; a<10; a++) {
        for (int b=0; b<10; b++) {
            for (int c=0; c<10; c++) {
                if (a!=b && b!=c && a!=c) {
                    number=a*100+b*10+c;
                    printf("%03d\n", number);
                }
            }
        }
    }
    return 0;
}
