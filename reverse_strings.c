// February programming challenge
//   -> Day 5 - Reverse strings
//   -> Swap each of the characters in the string so that it is inverted

#include <stdio.h>
#include <string.h>

int main() {
    char vari;
    char cdc[100];
    printf("Content : ");
    scanf("%s", cdc);

    for (int i=0; i<strlen(cdc)/2; i++) {
        vari=cdc[i];
        cdc[i]=cdc[strlen(cdc)-(i+1)];
        cdc[strlen(cdc)-(i+1)]=vari;
    }
    printf("Result : %s", cdc);
    return 0;
}
