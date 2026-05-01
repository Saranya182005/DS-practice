#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DIR_LENGTH 100
struct Node {
    char dir[MAX_DIR_LENGTH];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;
struct Node* createNode(char dir[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->dir, dir);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Add a new directory to history
void addDirectory(char dir[]) {
    struct Node* newNode = createNode(dir);
    // Remove forward history
    if (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = NULL;
    }
    if (current != NULL) {
        current->next = newNode;
        newNode->prev = current;
    }

    current = newNode;
    printf("Moved to directory: %s\n", dir);
}
// Move to previous directory
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s\n", current->dir);
    } else {
        printf("No previous directory.\n");
    }
}
// Move to next directory
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s\n", current->dir);
    } else {
        printf("No next directory.\n");
    }
}
// Display directory history
void displayHistory() {
    if (current == NULL) {
        printf("No directory history.\n");
        return;
    }
    struct Node* temp=current;
    while (temp->prev!=NULL)
        temp = temp->prev;

    printf("\nDirectory History:\n");
    while(temp!=NULL){
        if(temp==current)
            printf("-> %s(current)\n",temp->dir);
        else
            printf(" %s\n",temp->dir);
        temp=temp->next;
    }
}

// Free memory
void freeHistory(){
    struct Node* temp=current;
    while(temp&&temp->prev!=NULL)
        temp=temp->prev;
        
    while (temp) {
        struct Node* Delete=temp;
        temp=temp->next;
        free(Delete);
    }
}

int main(){
    int choice;
    char dirName[MAX_DIR_LENGTH];

    while(1){
        printf("1. Change Directory\n");
        printf("2. Go to Previous Directory\n");
        printf("3. Go to Next Directory\n");
        printf("4. Show Directory History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter directory path: ");
                fgets(dirName,sizeof(dirName),stdin);
                dirName[strcspn(dirName,"\n")]='\0'; 
                addDirectory(dirName);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                freeHistory();
                printf("Exiting..\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
