// February programming challenge
//   -> Day 20 - Tic-Tac-Toe game
//   -> Create a game of Tic-Tac-Toe where two players compete against each other

#include <stdio.h>
#include <ctype.h>

void displayGrid(char grid[3][3]) {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);
    printf("   |   |   \n");
}

int main() {
	printf("Welcome in Tic-Tac-Toe !\n");
	printf("Write : u for up, m for middle or d for down and l for left, m for middle or r for right.\n");

	char grid[3][3]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	int valid=0;
	int moves=0;
	char choice_player[2];
	int choice_row=0;
	int choice_column=0;

	while (valid!=1) {
		for (int i=0; i<2; i++) {
			displayGrid(grid);
			printf("Player %d : ", i);
			scanf(" %c %c", &choice_player[0], &choice_player[1]);

			switch (toupper(choice_player[0])) {
				case 'U': choice_row=0; break;
				case 'M': choice_row=1; break;
				case 'D': choice_row=2; break;
				default:
					printf("Please enter a valid letter");
					i--;
					continue;
			}

			switch(toupper(choice_player[1])) {
				case 'L': choice_column=0; break;
				case 'M': choice_column=1; break;
				case 'R': choice_column=2; break;
				default:
					printf("Please enter a valid letter");
					i--;
					continue;
			}

			if (grid[choice_row][choice_column]==' ') {
				grid[choice_row][choice_column]=(i==0) ? 'X' : 'O';
				moves++;
			} else {
				printf("You can't play here.\n");
				i--;
				continue;
			}

			for (int j = 0; j < 3; j++) {
				if (grid[j][0]==grid[j][1] && grid[j][1]==grid[j][2] && grid[j][0]!=' ') {
					printf("Player %d wins!\n", i+1);
					valid=1;
					return 1;
				}
				if (grid[0][j]==grid[1][j] && grid[1][j]==grid[2][j] && grid[0][j]!=' ') {
					printf("Player %d wins!\n", i+1);
					valid=1;
					return 1;
				}
			}

			if ((grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0]!=' ') ||
				(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[0][2]!=' ')) {
				printf("Player %d wins!\n", i+1);
				valid=1;
				return 1;
			}
			if (moves==9 && valid!=1) {
				printf("It's a draw!!\n");
				return 1;
			}

		}

	}
	return 0;
}
