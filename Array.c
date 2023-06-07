//Perform Insertion, Deletion and Traversal of Array
#include <stdio.h>
void insert(int a[], int n, int pos, int val);
void delete(int a[],int n, int pos);
void display(int a[],int n);
void main(){
    int a[100],i,option,position,value,num;
    printf("Enter the no.of elements in the array:");
    scanf("%d",&num);
    printf("Enter the elements in the array: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    do{
        printf("1.Insertion\n2.Deletion\n3.Traversal\n4.Exit\n");
        printf("Enter your option:");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the position: ");
                scanf("%d",&position);
                printf("Enter the value: ");
                scanf("%d",&value);
                insert(a,num,position,value);
                num++;
                display(a,num);
                break;
            case 2:
                printf("Enter the position: ");
                scanf("%d",&position);
                delete(a,num,position);
                num--;
                display(a,num);
                break;
            case 3:
                printf("The elements in the array are: ");
                display(a,num);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }while(option!=4);
}
void insert(int a[], int n, int pos, int val){
    for(int i=n-1;i>=pos;i--)
        a[i+1]=a[i];
    a[pos]=val;
}
void delete(int a[],int n, int pos){
    for(int i=pos;i<n-1;i++)
        a[i]=a[i+1];
}
void display(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}