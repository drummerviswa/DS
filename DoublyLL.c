//Doubly Linked List
#include <stdio.h>
#include <malloc.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertAtBeg(){
    if(head==NULL){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
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
        newNode->prev = NULL;
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
        newNode->prev = temp;
        newNode->next = NULL;
    }
}
void insertAtPosition(){
    int pos, i=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos==1){
        insertAtBeg();
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
        temp->next->prev = newNode;
        newNode->prev = temp;
    }
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Deleted element is %d\n", temp->data);
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
        struct node *temp1 = temp->next;
        temp->next = NULL;
        printf("Deleted element is %d\n", temp1->data);
        free(temp1);
    }
}
void deleteAtPosition(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else{
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
        temp->next = temp->next->next;
        temp->next->prev = temp;
        printf("Deleted element is %d\n", temp1->data);
        free(temp1);
    }
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
    do{
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insertAtBeg();
                    break;
            case 2: insertAtEnd();
                    break;
            case 3: insertAtPosition();
                    break;
            case 4: deleteAtBeginning();
                    break;
            case 5: deleteAtEnd();
                    break;
            case 6: deleteAtPosition();
                    break;
            case 7: display();
                    break;
        }
    }while(choice!=8);
}