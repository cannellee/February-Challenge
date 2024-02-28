// February programming challenge
//   -> Day 28 - Master Mind
//   -> Implement a Master Mind game in which the player tries to guess a sequence of colours in a limited number of attempts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    srand(time(NULL));
    const char *colors[6]={"r", "y", "b", "g", "w", "p"};
    char hidden_colors[4]={'\0'};
    for (int i=0; i<4; i++) {
        int index=rand()%6;
        hidden_colors[i]=*colors[index];
    }

    char given_colors[4]={'\0'};
    int guess[4]={-1};
    int round=0;
    int sum_guess=0;

    printf("Welcome to Master Mind !\n");
    printf("You have to find the combination of four colors in less than 10 rounds. \nFor that, you have to write only the first letter among these colors : Red, Yellow, Blue, Green, White, Purple\n");
    printf(" 1 - Correct color and correct position.\n 0 - Correct color but wrong position.\n -1 - Wrong color and wrong position.\n\n");

    while (sum_guess!=4 && round<10) {
        for (int i=0; i<4; i++) {
            guess[i]=-1;
        }
        printf("Write 4 colors : ");
        scanf("%s", given_colors);

        for (int j=0; j<4; j++) {
            given_colors[j]=tolower(given_colors[j]);
            if (!(given_colors[j]=='r' || given_colors[j]=='y' || given_colors[j]=='b' || given_colors[j]=='g' || given_colors[j]=='w' || given_colors[j]=='p')) {
                printf("One or many letters are invalid. Please retry.\n");
                return 1;
            }
        }

        sum_guess=0;
        for (int i=0; i<4; i++) {
            if (hidden_colors[i]==given_colors[i]) {
                guess[i]=1;
            } else {
                for (int j=0; j<4; j++) {
                    if (hidden_colors[i]==given_colors[j] && guess[i]!=1 && guess[i]!=0) {
                        guess[j]=0;
                        break;
                    }
                }
            }
            if (guess[i]!=0 && guess[i]!=1) {
				guess[i]=-1;
			}
            if (guess[i]==1) {
                sum_guess++;
            }
        }

        printf("Résultat : ");
        for (int m=0; m<4; m++) {
            printf("%d ", guess[m]);
        }
        printf("\n");
        round++;
    }

    if (sum_guess==4) {
        printf("Congratulations! You have guessed the correct combination.\n");
    } else {
        printf("Sorry, you couldn't guess the combination within 10 rounds.\n");
    }
    return 0;
}
