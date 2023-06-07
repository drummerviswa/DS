//Queue
#include <stdio.h>
#define max 20
void insertion();
void deletion();
void display();
int i,opt,rear,front,q[max],item;
void insertion(){
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
void deletion(){
    if((front==-1)||(rear==-1))
        printf("Queue is Empty\n");
    else{
        item=q[front];
        for(int i=0;i<=rear;i++)
            q[i]=q[i+1];
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
void main(){
    front=0;rear=-1;
    do{
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
        }
    }while(opt!=4);
}