#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This structure stores the contact information
struct Contact {
    char name[70];
    char phone[20];
    char email[70];
};

//Adds new contact
void addContact(struct Contact **contacts, int *count) {
    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter email address: ");
    scanf("%s", newContact.email);

    (*count)++;
    *contacts = (struct Contact *)realloc(*contacts, (*count) * sizeof(struct Contact));
    (*contacts)[(*count) - 1] = newContact;

    printf("Contact added successfully!\n");
}

//Displays all saved contacts
void viewContacts(struct Contact *contacts, int count) {
    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, contacts[i].name);
    }
}

//This searches for a contact by name, has to be exact, case sensitive
void searchContact(struct Contact *contacts, int count) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }

    printf("Contact not found\n");
}

//Edits the existing contact
void editContact(struct Contact *contacts, int count) {
    char searchName[100];
    printf("Enter name to edit: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new email address: ");
            scanf("%s", contacts[i].email);
            printf("Contact edited successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

//This deletes a contact
void deleteContact(struct Contact **contacts, int *count) {
    char searchName[50];
    printf("Enter name to delete: ");
    scanf("%s", searchName);

    for (int i = 0; i < *count; i++) {
        if (strcmp((*contacts)[i].name, searchName) == 0) {
            for (int j = i; j < (*count) - 1; j++) {
                (*contacts)[j] = (*contacts)[j + 1];
            }
            (*count)--;
            *contacts = (struct Contact *)realloc(*contacts, (*count) * sizeof(struct Contact));
            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    struct Contact *contacts = NULL;
    int count = 0;
    int choice;

    do {
        printf("\nContact Management System Menu:\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&contacts, &count);
                break;
            case 2:
                viewContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                editContact(contacts, count);
                break;
            case 5:
                deleteContact(&contacts, &count);
                break;
            case 6:
                free(contacts);
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
