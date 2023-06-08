#include <stdio.h>
#define max 100
void insert(int,int);
int del();
void display();
struct{
    int data;
    int priority;
}pq[max];
int front=-1,rear=-1;
void main(){
    int opt,ele,priority,element;
    do{
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                if(rear==max-1)
                    printf("Queue is Full\n");
                else{
                    printf("Enter the element to be inserted: ");
                    scanf("%d",&element);
                    printf("Enter the priority: ");
                    scanf("%d",&priority);
                    insert(element,priority);
                }
                break;
            case 2:
                if(front==-1)
                    printf("Queue is Empty\n");
                else{
                    ele=del();
                    printf("The deleted element is %d\n",ele);
                }
                break;
            case 3: 
                if(front==-1)
                    printf("Queue is Empty\n");
                else
                    display();
                break;
        }
    }while(opt!=4);
}
void insert(int e, int priority){
    int i;
    if (front == -1)
        front = 0;
    if (rear == -1){
        rear = 0;
        pq[rear].data = e;
        pq[rear].priority = priority;
    }
    else{
        for (i = rear; i >= front; i--){
            if (priority > pq[i].priority)
                pq[i + 1] = pq[i];
            else
                break;
        }
        pq[i + 1].data = e;
        pq[i + 1].priority = priority;
        rear++;
    }
}
int del(){
    int e;
    e=pq[rear].data;
    for(int i=rear;i>front;i--){
        pq[i].data=pq[i-1].data;
        pq[i].priority=pq[i-1].priority;
    }
    rear--;
    return e;
}
void display(){
    for(int i=front;i<=rear;i++)
        printf("%d ",pq[i].data);
    printf("\n");
}