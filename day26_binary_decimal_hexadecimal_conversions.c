// February programming challenge
//   -> Day 26 - Binary-decimal-hexadecimal conversions
//   -> Create a program that converts a binary number into its decimal and hexadecimal representation, and vice versa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

int is_binary(const char *binary) {
    while (*binary) {
        if (*binary!='0' && *binary!='1') return 0;
        binary++;
    }
    return 1;
}

int is_decimal(const char *decimal) {
    while (*decimal) {
        if (!isdigit(*decimal)) return 0;
        decimal++;
    }
    return 1;
}

int is_hex(const char *hex) {
    while (*hex) {
        if (!isxdigit(*hex)) return 0;
        hex++;
    }
    return 1;
}

unsigned long dec_to_bin(unsigned long decimal) {
	unsigned long binary=0;
    unsigned long base=1;

    while (decimal>0) {
    	binary+=(decimal%2)*base;
		decimal/=2;
		base*=10;
    }
    return binary;
}

unsigned long hex_to_dec(const char* hex) {
    unsigned long decimal=0;
    int length=strlen(hex);
    int base=1;

    for (int i=length-1; i>=0; i--) {
        if (hex[i]>='0' && hex[i]<='9') decimal+=(hex[i]-'0')*base;
        else if (hex[i]>='A' && hex[i]<='F') decimal+=(hex[i]-'A'+10)*base;
        else if (hex[i]>='a' && hex[i]<='f') decimal+=(hex[i]-'a'+10)*base;
        base*=16;
    }
    return decimal;
}

unsigned long bin_to_dec(unsigned long binary) {
    unsigned long decimal=0;
    unsigned long base=1;

    while (binary>0) {
		decimal+=(binary%10)*base;
		binary/=10;
		base*=2;
	}
	return decimal;
}

char* dec_to_hex(unsigned long decimal) {
	static char hex_value[MAX_INPUT_SIZE];
	strcpy(hex_value, "");
    char hex_chars[17]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int index=0;

    if (decimal==0) strcpy(hex_value, "0");
	else {
		while (decimal>0) {
			int remainder=decimal%16;
			char hex_char=hex_chars[remainder];
			strncat(hex_value, &hex_char, 1);
			decimal/=16;
		}
	}

	int length=strlen(hex_value);
	for (int i=0; i<length/2; ++i) {
		char temp=hex_value[i];
		hex_value[i]=hex_value[length-i-1];
		hex_value[length-i-1]=temp;
	}
	return hex_value;
}

int main() {
	char request;
	printf("Write B/b for Binary, D/d for Decimal or H/h for Hexadecimal : ");
	scanf(" %c", &request);

	switch(tolower(request)) {
		case 'b':
			char binary_input[MAX_INPUT_SIZE];
			printf("Enter the binary : ");
			scanf("%s", binary_input);
			if (!is_binary(binary_input)) {
				printf("Invalid binary input\n");
				return 1;
			}
			unsigned long binary=strtoul(binary_input, NULL, 2);
			printf("Decimal : %lu\n", bin_to_dec(binary));
			printf("Hexadecimal : %s\n", dec_to_hex(bin_to_dec(binary)));
			break;
		case 'd':
			char decimal_input[MAX_INPUT_SIZE];
			printf("Enter the decimal : ");
			scanf("%s", decimal_input);
			if (!is_decimal(decimal_input)) {
				printf("Invalid decimal input\n");
				return 1;
			}
			unsigned long decimal=strtoul(decimal_input, NULL, 10);
			printf("Binary : %lu\n", dec_to_bin(decimal));
			printf("Hexadecimal : %s\n", dec_to_hex(decimal));
			break;
		case 'h':
			char hex_input[MAX_INPUT_SIZE];
			printf("Enter the hexadecimal : ");
			scanf("%s", hex_input);
			if (!is_hex(hex_input)) {
				printf("Invalid hexadecimal input\n");
				return 1;
			}
			decimal=hex_to_dec(hex_input);
			printf("Binary : %lu\n", dec_to_bin(decimal));
			printf("Decimal : %lu\n", decimal);
			break;
		default:
			printf("Error");
			break;
	}
	return 0;
}
