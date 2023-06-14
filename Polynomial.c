#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
}*headA=NULL,*headB=NULL,*headC=NULL;
void create(struct node **head){
    struct node *temp,*nn;
    int i,n;
    printf("Enter the no.of items: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coeff: ");
        scanf("%d",&nn->coeff);
        printf("Enter the exp: ");
        scanf("%d",&nn->exp);
        nn->next=NULL;
        if(*head==NULL){
            *head=nn;
            temp=nn;
        }
        else{
            temp->next=nn;
            temp=nn;
        }
    }
}
void display(struct node *head){
    struct node *t;
    t=head;
    while(t!=NULL){
        printf("%dx^%d ",t->coeff,t->exp);
        t=t->next;
        if(t!=NULL)
            printf("+");
    }
    printf("\n");
}
void add(){
    struct node *t1,*t2,*t3,*nn;
    t1=headA;
    t2=headB;
    t3=headC;
    while(t1!=NULL&&t2!=NULL){
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->next=NULL;
        if(t1->exp==t2->exp){
            nn->coeff=t1->coeff+t2->coeff;
            nn->exp=t1->exp;
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->exp>t2->exp){
            nn->coeff=t1->coeff;
            nn->exp=t1->exp;
            t1=t1->next;
        }
        else{
            nn->coeff=t2->coeff;
            nn->exp=t2->exp;
            t2=t2->next;
        }
        if(headC==NULL){
            headC=nn;
            t3=nn;
        }
        else{
            t3->next=nn;
            t3=nn;
        }
    }
    while(t1!=NULL){
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->next=NULL;
        nn->coeff=t1->coeff;
        nn->exp=t1->exp;
        t1=t1->next;
        t3->next=nn;
        t3=nn;
    }
    while(t2!=NULL){
        struct node *nn = (struct node *)malloc(sizeof(struct node));
        nn->next=NULL;
        nn->coeff=t2->coeff;
        nn->exp=t2->exp;
        t2=t2->next;
        t3->next=nn;
        t3=nn;
    }
}
void main(){
    int opt;
    do{
        printf("1.Create A\n2.Create B\n3.Display A\n4.Display B\n5.Add\n6.Display\nEnter your option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                create(&headA);
                break;
            case 2:
                create(&headB);
                break;
            case 3:
                display(headA);
                break;
            case 4:
                display(headB);
                break;
            case 5:
                add();
                break;
            case 6:
                display(headC);
                break;
        }
    }while(opt!=7);
}
