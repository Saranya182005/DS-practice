//congo line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char *ch;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;
struct Node *tail=NULL;

//insertAtBegin
void insertAtBegin(char *chr){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->ch=chr;
    newNode->next=head;
    newNode->prev=NULL;
    
    if(head == NULL){
        head=newNode;
        tail=newNode;
    }else
     head=newNode;
     
}

//insertAtEnd
void insertAtEnd(char *chr){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->ch=chr;
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail == NULL)
    {
        tail=newNode;
        head=newNode;
    }else
        tail->next=newNode;
      
}

//deleteAtBegin
void delAtBegin(){
    struct Node *temp=head;
    head=temp->next;
    free(temp);
   }

//display
void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%s->",temp->ch);
        temp=temp->next;
    }
    printf("NULL");
    
}

int main(){
    insertAtBegin("saranya");
    insertAtBegin("siva");
    insertAtBegin("swathi");
    insertAtBegin("robert");
    insertAtBegin("hari");
    display();
    printf("\n");
    insertAtEnd("Arun");
    display();
    printf("\n");
    delAtBegin();
    display();
}
