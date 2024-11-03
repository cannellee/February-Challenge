// February programming challenge
//   -> Day 13 - Stopwatch
//   -> Write a program that acts like a stopwatch, capable of measuring elapsed time

#include <stdio.h>
#include <time.h>

int main() {
    time_t debut, fin;
    double temps_ecoule;
    char ask[50];
    time(&debut);

    printf("The timer starts, enter what you want : ");
    scanf("%s", ask);

    time(&fin);
    temps_ecoule=difftime(fin, debut);
    printf("The stopwatch has stopped. Elapsed time: %.2f seconds\n", temps_ecoule);

    return 0;
}
