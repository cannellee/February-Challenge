// February programming challenge
//   -> Day 14 - Character string analyser
//   -> Analyse a character string to identify letters, numbers, special characters, etc

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	long count_alpha=0;
	long count_alpha_upper=0;
	long count_alpha_lower=0;
	long count_alpha_vowels=0;
	long count_alpha_consonants=0;
	long count_number=0;
	long count_punct=0;
	long count_punct_apos=0;
	long count_space=0;
	long count_other=0;

	char cdc[500];
	printf("Your text : ");
	fgets(cdc, sizeof(cdc), stdin);

	for (int i=0; i<strlen(cdc); i++) {
		if (isalpha(cdc[i])) {
			count_alpha++;
			if (isupper(cdc[i])) {
				count_alpha_upper++;
			} else {
				count_alpha_lower++;
			}

			switch (tolower(cdc[i])) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y':
					count_alpha_vowels++;
					break;
				default:
					count_alpha_consonants++;
					break;
			}
		} else if (isdigit(cdc[i])) {
			count_number++;
		} else if (isspace(cdc[i])) {
			count_space++;
		} else if (ispunct(cdc[i])) {
			count_punct++;
			if (cdc[i]=='\'') {
				count_punct_apos++;
			}
		} else {
			count_other++;
		}
	}

	long count_words=count_space+count_punct_apos;

	printf("In the text, you have :\n -%ld words,\n -%ld letters with :\n  -%ld lower & %ld upper,\n  -%ld vowels & %ld consonants\n", count_words, count_alpha, count_alpha_lower, count_alpha_upper, count_alpha_vowels, count_alpha_consonants);
	printf(" -%ld numbers, \n -%ld spaces, \n -%ld punctuation, \n -%ld other.", count_number, count_space, count_punct, count_other);
	return 0;
}
