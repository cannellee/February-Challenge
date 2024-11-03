// February programming challenge
//   -> Day 3 - Hangman
//   -> Create a text version of the hangman where player have to guess a word

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
	srand(time(NULL));
	const char *list_words[]={"banana", "lamp", "ocean", "bicycle", "elephant", "castle", "notebook", "rainbow", "telescope", "butterfly", "guitar", "mountain", "chocolate", "dragon",
			"pillow", "galaxy", "pineapple", "laptop", "fireworks", "kangaroo", "diamond", "robot", "waterfall", "moonlight", "basketball", "seashell", "parrot", "tornado", "snowflake",
			"crocodile", "jellyfish", "eiffel", "universe", "coffee", "spider", "sunflower", "satellite", "pinecone", "symphony", "trampoline", "rainbow", "zebra", "adventure", "sushi",
			"thunder", "bubble", "compass", "coconut", "whisper", "iceberg", "bonsai", "mermaid", "harmony", "bamboo", "blizzard", "enigma", "galaxy", "quasar", "oasis", "lemonade", "cactus",
			"sandcastle", "firefly", "starlight", "carousel", "potion", "monsoon", "cinnamon", "avalanche", "lighthouse", "caterpillar", "volcano", "seahorse", "tangerine", "chameleon"};

	int size=sizeof(list_words)/sizeof(list_words[0]);
    int num_word_chosen=rand()%size;

    char word_chosen[strlen(list_words[num_word_chosen])+1];
    strcpy(word_chosen, list_words[num_word_chosen]);

    char hidden_word[strlen(list_words[num_word_chosen])+1];
    for (int i = 0; i < strlen(list_words[num_word_chosen])*2-1; i+=2) {
    	hidden_word[i]='_';
    	hidden_word[i+1]=' ';
    }
    hidden_word[strlen(list_words[num_word_chosen])*2-1]='\0';

    char guess;
    char false_letters[27]={'\0'};
    int remaining_shots=11;

    while (remaining_shots>=0 && strcmp(word_chosen, hidden_word) != 0) {
    	printf("Number of remaining shots : %d\n", remaining_shots+1);
        printf(" _______\n");
        printf(" |     |\n");

        switch (remaining_shots) {
            case 11:
        	case 10:
        	case 9:
        	case 8:
        	case 7:
        	case 6:
        		printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 5:
                printf(" |     O\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 4:
                printf(" |     O\n");
                printf(" |     |\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 3:
                printf(" |     O\n");
                printf(" |    /|\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 2:
                printf(" |     O\n");
                printf(" |    /|\\\n");
                printf(" |\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 1:
                printf(" |     O\n");
                printf(" |    /|\\\n");
                printf(" |    /\n");
                printf(" |\n");
                printf(" |\n");
                break;
            case 0:
            	printf(" |     O\n");
            	printf(" |    /|\\\n");
            	printf(" |    /\\\n");
            	printf(" |\n");
            	printf(" |\n");
            	strcpy(word_chosen, hidden_word);
            	break;
        }
        printf("_|_________\n\n");
        printf("\nThe word : %s \n", hidden_word);


		printf("Your proposition : ");
		scanf(" %c", &guess);
		if (!isalpha(guess)) {
			printf("Invalid input! Please enter an alphabetic character.\n\n");
		    continue;
		}
		guess=tolower(guess);
		printf("\n\n");

		if (strcmp(list_words[num_word_chosen], hidden_word)==0) {
			printf("Well done! You've won!");
			remaining_shots=0;
			break;
		} else {
			int found=0;
			for (int i=0; word_chosen[i]!='\0'; i++) {
				if (word_chosen[i]==tolower(guess)) {
					hidden_word[i*2]=tolower(guess);
					found=1;
				}
			}

			if (!found) {
				int already_guessed=0;
				for (int j=0; false_letters[j]!='\0'; j++) {
					if (false_letters[j]==guess) {
						already_guessed=1;
						break;
					}
				}

				if (!already_guessed) {
					false_letters[strlen(false_letters)]=guess;
					remaining_shots--;
				} else {
					printf("You've already given this letter!\n\n");
				}
			} else {
				for (int k=0; word_chosen[k]!='\0'; k++) {
					if (word_chosen[k]==tolower(guess)) {
						hidden_word[k*2]=tolower(guess);
					}
				}
			}
		}
		if (remaining_shots<0) {
			break;
		}
    }
    printf("Game over, the word was \"%s\"", list_words[num_word_chosen]);
	return 0;
}
