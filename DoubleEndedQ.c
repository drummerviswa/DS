//Double Ended Queue
#include <stdio.h>
#define max 20
int q[max],front=-1,rear=-1,item;
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();
void main(){
    int opt;
    do{
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                insert_front();
                break;
            case 2:
                insert_rear();
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
        }
    }while(opt!=6);
}
void insert_front(){
    int item;
    if(front==0)
        printf("Queue is Full\n");
    else{
        printf("Enter the element to be inserted: ");
        scanf("%d",&item);
        if(front==-1){
            front=0;rear=0;
        }
        else
            front--;
        q[front]=item;
    }
}
void insert_rear(){
    int item;
    if(rear==max-1)
        printf("Queue is Full\n");
    else{
        printf("Enter the element to be inserted: ");
        scanf("%d",&item);
        if(rear==-1){
            front=0;rear=0;
        }
        else
            rear++;
        q[rear]=item;
    }
}
void delete_front(){
    if(front==-1)
        printf("Queue is Empty\n");
    else{
        item=q[front];
        if(front==rear){
            front=-1;rear=-1;
        }
        else if(front==max-1)
            front=0;
        else
            front++;
        printf("The deleted element is %d\n",item);
    }
}
void delete_rear(){
    if(rear==-1)
        printf("Queue is Empty\n");
    else{
        item=q[rear];
        if(front==rear){
            front=-1;rear=-1;
        }
        else
            rear--;
        printf("The deleted element is %d\n",item);
    }
}
void display(){
    if(front==-1||rear==-1)
        printf("Queue is Empty\n");
    else{
        for(int i=front;i<=rear;i++)
            printf("%d ",q[i]);
        printf("\n");
    }
}
