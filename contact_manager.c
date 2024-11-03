// February programming challenge
//   -> Day 10 - Contact manager
//   -> Implement a program for adding, deleting and displaying contacts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
	char first_name[50];
	char last_name[50];
	char phone[15];
};

struct Contact contacts[MAX_CONTACTS];
int number_contacts=0;


void add_contact() {
	if (number_contacts<MAX_CONTACTS) {
		printf("Enter the first name : ");
		scanf("%49s", contacts[number_contacts].first_name);
		getchar();

		printf("Enter the last name : ");
		scanf("%49s", contacts[number_contacts].last_name);
		getchar();

		printf("Enter the phone : ");
		scanf("%14s", contacts[number_contacts].phone);
		getchar();

		number_contacts++;
	} else {
		printf("The address book is full.\n");
	}
}


void duplicate_contact() {
    if (number_contacts < MAX_CONTACTS) {
        char first_name[50];
        char last_name[50];
        printf("Enter the first name of the contact you want to duplicate: ");
        scanf("%49s", first_name);
        getchar();

        printf("Enter the last name of the contact you want to duplicate: ");
        scanf("%49s", last_name);
        getchar();

        for (int i = 0; i < number_contacts; i++) {
            if (strcmp(first_name, contacts[i].first_name) == 0 && strcmp(last_name, contacts[i].last_name) == 0) {
                strcpy(contacts[number_contacts].first_name, first_name);
                strcpy(contacts[number_contacts].last_name, last_name);
                strcpy(contacts[number_contacts].phone, contacts[i].phone);
                number_contacts++;
                break;
            }
        }
    } else {
        printf("The address book is full.\n");
    }
}


void delete_contact() {
    char first_name[50];
    char last_name[50];
    printf("Enter the first name of the contact you want to delete: ");
    scanf("%49s", first_name);
    getchar();

    printf("Enter the last name of the contact you want to delete: ");
    scanf("%49s", last_name);
    getchar();

    for (int i = 0; i < number_contacts; i++) {
        if (strcmp(first_name, contacts[i].first_name) == 0 && strcmp(last_name, contacts[i].last_name) == 0) {
            for (int j = i; j < number_contacts - 1; j++) {
                strcpy(contacts[j].first_name, contacts[j+1].first_name);
                strcpy(contacts[j].last_name, contacts[j+1].last_name);
                strcpy(contacts[j].phone, contacts[j+1].phone);
            }
            number_contacts--;
            break;
        }
    }
}


void delete_all_contacts() {
	char choice_delete;
	printf("Are you sure to delete all contacts ? (y/n) : ");
	scanf(" %c", &choice_delete);
	if (choice_delete=='y' || choice_delete == 'Y') {
		printf("Deleting all contacts...\n");
		number_contacts=0;
		printf("All contacts are deleted\n");
	} else {
		printf("Operation cancelled\n");
	}
}


void show_all_contacts() {
	printf("List of contacts :\n");
	for (int i=0; i<number_contacts; i++) {
		printf("Contact %d : \n", i+1);
		printf("First name : %s\n Last name : %s\nPhone : %s\n\n", contacts[i].first_name, contacts[i].last_name, contacts[i].phone);
	}
}


int main() {
	int choice;

	do {
		printf("\nMenu:\n 1. Add a contact\n 2. Duplicate a contact\n 3. Delete a contact\n 4. Delete all contacts\n 5. Show all contacts\n 6. Exit\n");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				add_contact();
				break;
			case 2:
				duplicate_contact();
				break;
			case 3:
				delete_contact();
				break;
			case 4:
				delete_all_contacts();
				break;
			case 5:
				show_all_contacts();
				break;
			case 6:
				printf("Bye bye !");
				return 1;
			default:
				printf("Invalid choice");
				break;
		}
	} while (choice!=6);

	return 0;
}
