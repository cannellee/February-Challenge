// February programming challenge
//   -> Day 27 - Reverse words
//   -> Create a program that reverses the order of words in a given sentence

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[500];
    printf("Write your text : ");
    fgets(text, sizeof(text), stdin);

    char result[500] = "";

    int len=strlen(text);
    int word_end=len-1;
    for (int i=len-1; i>=0; i--) {
        if (isspace(text[i]) || ispunct(text[i]) || i==0) {
            int word_start=(i==0) ? 0 : i + 1;
            for (int j=word_start; j<=word_end; j++) {
                strncat(result, &text[j], 1);
            }
            if (ispunct(text[i]) || i!=0) {
                strncat(result, &text[i], 1);
            }
            if (i!=0) {
                strcat(result, " ");
            }
            word_end=i-1;
        }
    }

    printf("Reversed Words: %s\n", result);

    return 0;
}
