#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

void addContact(Contact contacts[], int *numContacts) {
    if (*numContacts == MAX_CONTACTS) {
        printf("Phonebook is full. Cannot add more contacts.\n");
        return;
    }

    Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

void displayContacts(Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("Name\t\tPhone Number\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

void searchContact(Contact contacts[], int numContacts, char name[]) {
    int found = 0;

    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name\t\tPhone Number\n");
            printf("-----------------------------------\n");
            printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;
    char searchName[MAX_NAME_LENGTH];

    while (1) {
        printf("\nPhonebook\n");
        printf("--------------------------------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                printf("Enter the name to search: ");
                scanf("%s", searchName);
                searchContact(contacts, numContacts, searchName);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
