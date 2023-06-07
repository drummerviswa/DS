//Stack
#include <stdio.h>
#define max 5
int stack[max],top=-1;
void push(int val);
int pop();
void display();
void main(){
    int option,val;
    do{
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your option:");
    scanf("%d",&option);
    switch(option){
        case 1:
            if(top==max-1)
                printf("Stack is Full\n");
            else{
                printf("Enter the value: ");
                scanf("%d",&val);
                push(val);
            }
            break;
        case 2:
            if(top==-1)
                printf("Stack is Empty\n");
            else
                val = pop();
                printf("The popped element is %d\n",val);
            break;
        case 3:
            if(top==-1)
                printf("Stack is Empty\n");
            else
                display();
            break;
        }
    }while(option!=4);
}
void push(int val){
    stack[++top]=val;
}
int pop(){
    return stack[top--];
}
void display(){
    for(int i=top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}
