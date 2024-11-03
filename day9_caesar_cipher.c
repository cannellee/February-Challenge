// February programming challenge
//   -> Day 9 - Caesar cipher
//   -> Implement Caesar encryption to encrypt and decrypt messages

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("(C/c : Cesar ; A/a : Arabic)\nYou're limited at 100 characters\n");

    char alphabet_one[27]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    char continue_flag='y';
    char alphabet_two[27];

    while (tolower(continue_flag)=='y') {
        char type;
        printf("Write the type of input (C/c or A/a) : ");

        if (scanf(" %c", &type)!=1 || (tolower(type)!='c' && tolower(type)!='a')) {
            printf("Invalid input.\n");
            continue;
        }

        int shift;
        printf("The shift (ex : A->B : 1) : ");
        scanf("%d", &shift);

        for (int i=0; alphabet_one[i]!='\0'; i++) {
            int index=(i+shift)%26;
            alphabet_two[i]=alphabet_one[index];
        }

        char cdc[100];
        printf("Enter the text to encrypt: ");
        scanf(" %[^\n]s", cdc);

        for (int j = 0; j < strlen(cdc); j++) {
            if (isalpha(cdc[j])) {
                if (islower(cdc[j])) {
                    printf("%c", alphabet_two[(cdc[j]-'a')]);
                } else if (isupper(cdc[j])) {
                    printf("%c", toupper(alphabet_two[(tolower(cdc[j])-'a')]));
                }
            } else {
                printf("%c", cdc[j]);
            }
        }

        printf("\nDo you want to convert ? (y/n): ");
        scanf(" %c", &continue_flag);
    }
    return 0;
}
