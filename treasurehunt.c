#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
struct Node {
    char hint[100];
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(char hint[]) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->hint, hint);
    newnode->next = NULL;
    return newnode;
}

// Insert at the end of the list
void addatend(char hint[]) {
    struct Node* newnode = createNode(hint);
    
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("'%s' added to the hints\n", hint);
}

// Display all hints
void display() {
    if (head == NULL) {
        printf("No hints available\n");
        return;
    }

    struct Node* temp = head;
    printf("Hints:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->hint);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int choice;
    char hintName[100];

    while (1) {
        printf("\n--- Hint Menu ---\n");
        printf("1. Give Hint\n2. Display Hints\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline after number input

        switch (choice) {
            case 1:
                printf("Enter hint: ");
                fgets(hintName, sizeof(hintName), stdin);
                hintName[strcspn(hintName, "\n")] = '\0'; // remove newline
                addatend(hintName);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Enter a valid choice.\n");
        }
    }

    return 0;
}
