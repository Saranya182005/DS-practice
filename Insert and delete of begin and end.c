//DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
//Node creation
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* tail=NULL;

//insertAtBeg
void insertAtBeg(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->prev=NULL;
newNode->next=head;

if(head!=NULL){
    head->prev=newNode;
} else {
    tail=newNode;
}
head=newNode;
}

// insertAtEnd
void insertAtEnd(int data){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
newNode->prev=tail;

if(tail!=NULL){
    tail->next=newNode;
} else {
    head=newNode;
}
tail=newNode;
}

//deleteAtBeg
void deleteAtBeg(){
    if(head==NULL){
        return;
    }
    struct Node* temp=head;
    if(head->next==NULL){
        head=NULL;
        tail=NULL;
    } else {
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
}

// deleteAtEnd
void deleteAtEnd(int data){
    if(tail==NULL){
        return;
    }
    struct Node* temp=tail;
    if(tail->prev == NULL){
        head=NULL;
        tail=NULL;
    } else{
        tail=tail->prev;
        tail->next=NULL;
    }
    free(temp);
}

// Display function
void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

// Main function
int main(){
    printf("Insert at the begin..");
    printf("\n");
    insertAtBeg(5);
    insertAtBeg(6);
    insertAtBeg(7);
    display();
    printf("\n");
    printf("Insert at the end..");
    printf("\n");
    insertAtEnd(8);
    insertAtEnd(9);
    display();
    printf("\n");
    printf("Delete at the beg..");
    printf("\n");
    deleteAtBeg(5);
    display();
    printf("\n");
    printf("Delete at the end..");
    printf("\n");
    deleteAtEnd(9);
    display();
    return 0;
}
