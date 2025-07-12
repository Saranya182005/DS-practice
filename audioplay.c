//singly linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char song[100];
    struct Node *next;
};
//head - declare
struct Node *head=NULL;

struct Node *createNode(char song[])
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song,song);
    newNode->next=NULL;
    return newNode;
}

void addSong(char song[])
{
    struct Node *newNode=createNode(song);
    newNode->next=head;
    head=newNode;
    printf("%s added to playlist\n",song);
}

void display()
{
    if(head==NULL) //newline
    {
        printf("No songs to play...");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%s ",temp->song);
        printf("\n");
        temp=temp->next;
    }
    //printf("NULL");
   // printf("\n");
}
int main()
{
    int choice;
    char songName[100];
    while(100)
    {
    printf("Choice 1: Add a song\nChoice 2: Display songs\nChoice 3: Exit\nEnter your choice: ");
    scanf("%d",&choice);
    getchar();  //newline
    switch(choice)
    {
        case 1:
          printf("Enter song name: ");
          fgets(songName, sizeof(songName),stdin); //newline
          songName[strcspn(songName,"\n")]=0; //newline
          addSong(songName);
          break;
        case 2:
           display();
          // printf("\n");
           break;
        case 3:
           printf("Exiting playlist");
           exit(0);
        default:
           printf("Enter valid choice");
    }
    }
    return 0;
}
