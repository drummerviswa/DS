#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void inserAtBeg(){
    if(head==NULL){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    }
    else{
        printf("List is not empty\n");
    }
}
void insertAtEnd(){
    if(head==NULL){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }
    else{
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void insertAtPosition(){
    int pos, i=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos==1){
        inserAtBeg();
    }
    else{
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        struct node *temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void deleteAtPosition(){
    int pos, i=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos==1){
        deleteAtBeginning();
    }
    else{
        struct node *temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}
void display(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    int choice;
    printf("Singly Linked List\n");
    do{
    printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at end\n6. Delete at position\n7. Display\n8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            inserAtBeg();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            display();
            break;
    }
    }while(choice !=8);
}