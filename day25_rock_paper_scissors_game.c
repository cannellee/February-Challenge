// February programming challenge
//   -> Day 15 - Rock-paper-scissors game
//   -> Implement a classic game of rock-paper-scissors where one player takes on the computer

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	printf("R - Rock, P - Paper, S - Scissors, E - Exit");
	char choices[3]={'P', 'R', 'S'};
	char choice_player='P';
	unsigned score_player=0;
	unsigned score_robot=0;

	while (choice_player!='E' && choice_player!='e') {
		char choice_robot=choices[rand()%3];
		printf("\nYour choice : ");
		scanf(" %c", &choice_player);
		getchar();

        if (choice_player=='R' || choice_player=='P' || choice_player=='S') {
            if (choice_player == choice_robot) {
                printf("Equality\n");
            } else if ((choice_player=='R' && choice_robot=='S') ||
                       (choice_player=='P' && choice_robot=='R') ||
                       (choice_player=='S' && choice_robot=='P')) {
                score_player++;
                printf("Player wins this round.\n");
            } else {
                score_robot++;
                printf("Robot wins this round.\n");
            }
        } else if (choice_player!='E' && choice_player!='e') {
            printf("Please enter a valid letter.\n");
        } else {
        	printf("Exit...\n");
        }
    }

	if (score_player<score_robot) {
		printf("The robot win this game with : %u - %u.", score_player, score_robot);
	} else if (score_player>score_robot) {
		printf("The player win this game with : %u - %u.", score_player, score_robot);
	} else {
		printf("No one win, with %u - %u.", score_player, score_robot);
	}
	return 0;
}
