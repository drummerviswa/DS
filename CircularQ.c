//Circular Queue
#include <stdio.h>
#define max 20
void insertion();
int deletion();
void display();
int i,opt,rear,front,q[max],item;
void main(){
    int opt,val;
    do{
        printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                insertion();
                break;
            case 2:
                val = deletion();
                if(val!=-1)
                    printf("The deleted element is %d\n",val);
                break;
            case 3:
                display();
                break;
        }
    }while(opt!=4);
}
void insertion(){
    int num;
    printf("Enter the element to be inserted: ");
    scanf("%d",&num);
    if((front==0&&rear==max-1))
        printf("Queue is Full\n");
    else{
        if((front==-1&&rear==-1)||(front==rear+1)){
            front=0;rear=0;
        }
        else if(rear==max-1&&front!=0)
            rear=0;
        else
            rear++;
        q[rear]=num;
    }
}
int deletion(){
    int val;
    if(front==-1&&rear==-1)
        printf("Queue is Empty\n");
    else{
        val = q[front];
        if(front==rear){
            front=-1;rear=-1;
        }
        else if(front==max-1)
            front=0;
        else
            front++;
        return val;
    }
}
void display(){
    if(front==-1&&rear==-1)
        printf("Queue is Empty\n");
    else{
        if(front<=rear){
            for(int i=front;i<=rear;i++)
                printf("%d ",q[i]);
        }
        else{
            // for(int i=front;i<=max-1;i++)
            //     printf("%d ",q[i]);
            for(int i=0;i<=rear;i++)
                printf("%d ",q[i]);
        }
        printf("\n");
    }
}