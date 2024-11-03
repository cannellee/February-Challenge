// February programming challenge
//   -> Day 8 - Temperature conversions
//   -> Write a program that allows the user to convert a temperature from one unit to another

#include <stdio.h>
#include <ctype.h>

int main() {
    printf("(C/c : Celsius ; F/f : Fahrenheit ; K/k : Kelvin)\n");

    char continue_flag = 'y';
    while (tolower(continue_flag) == 'y') {
        float degree;
        char flow_temp;
        printf("Write the flow temperature scale (number and scale) : ");
        if (scanf("%f %c", &degree, &flow_temp) != 2 || (tolower(flow_temp) != 'c' && tolower(flow_temp) != 'f' && tolower(flow_temp) != 'k')) {
            printf("Invalid input.\n");
            continue;
        }

        char inlet_temp;
        printf("Write the inlet temperature scale : ");
        if (scanf(" %c", &inlet_temp) != 1 || (tolower(inlet_temp) != 'c' && tolower(inlet_temp) != 'f' && tolower(inlet_temp) != 'k')) {
            printf("Invalid input.\n");
            continue;
        }

        if (tolower(flow_temp) == tolower(inlet_temp)) {
            printf("Degree : %.2f\n", degree);
            continue;
        }

        switch (tolower(flow_temp)) {
    		case 'c':
    			if (tolower(inlet_temp)=='f') { //Celsius -> Fahrenheit
    				degree=degree*9/5+32;
    			} else if (tolower(inlet_temp)=='k') { //Celsius -> Kelvin
    				degree=degree+273.15;
    			} else {
    				printf("Please enter a valid letter");
    				return 1;
    			}
    			break;
    		case 'f':
    			if (tolower(inlet_temp)=='c') { //Fahrenheit -> Celsius
    				degree=(degree-32)/(9/5);
    			} else if (tolower(inlet_temp)=='k') { //Fahrenheit -> Kelvin
    				degree=(degree-32)*5/9+273.15;
    			} else {
    				printf("Please enter a valid letter");
    				return 1;
    			}
    			break;
    		case 'k':
    			if (tolower(inlet_temp)=='c') { //Kelvin -> Celsius
    				degree=degree-273.15;
    			} else if (tolower(inlet_temp)=='f') { //Kelvin -> Fahrenheit
    				degree=(degree-273.15)*9/5+32;
    			} else {
    				printf("Please enter a valid letter");
    				return 1;
    			}
    			break;
    		default:
    			printf("Please enter a valid letter");
    			return 1;
    	}

        printf("Converted temperature: %.2f\n", degree);

        printf("Do you want to convert another temperature? (y/n): ");
        scanf(" %c", &continue_flag);
    }

    return 0;
}
