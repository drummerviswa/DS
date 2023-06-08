#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
void push();
void pop();
void enqueue();
void dequeue();
void display();
void stack();
void queue();

void main(){
    printf("Main Menu:\nStack and Queue using Linked List\n");
    int choice;
    do{
        printf("1. Stack\n2. Queue\n3.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: stack();
                    break;
            case 2: queue();
                    break;
        }
    }while(choice!=3);
}
void stack(){
    int choice;
    do{
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
        }
    }while(choice!=4);
}
void queue(){
    int choice;
    do{
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: enqueue();
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
    }
    }while(choice!=4);
}
void push(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}
void pop(){
    if(head==NULL){
        printf("Stack is empty\n");
    }
    else{
        struct node *temp = head;
        printf("Popped element is %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}
void enqueue(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    if(head==NULL){
        newNode->next = head;
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void dequeue(){
    if(head==NULL){
        printf("Queue is empty\n");
    }
    else{
        struct node *temp = head;
        head = head->next;
        free(temp);
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
    }
    printf("\n");
}
