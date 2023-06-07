//To perform Matrix Manupulation
#include <stdio.h>
#include <malloc.h>
void add();
void sub();
void multiply();
void display(int *mat,int m,int n);
void *getdata(int m,int n);
void main(){
    int opt;
    do{
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Exit\n");
        printf("Enter your option:");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                add();
                break;
            case 2:
                sub();
                break;
            case 3:
                multiply();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }while(opt!=4);
}
void *getdata(int m,int n){
    int *mat;
    mat=(int *)malloc(m*n*sizeof(int));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i*n+j]);
        }
    }
    return mat;
}
void add(){
    int m1,m2,n1,n2;
    int *a,*b,*c;
    int i,j;
    do{
        printf("Enter the no.of rows and columns of matrix 1:");
        scanf("%d%d",&m1,&n1);
        printf("Enter the no.of rows and columns of matrix 2:");
        scanf("%d%d",&m2,&n2);
        a=(int *)malloc(m1*n1*sizeof(int));
        b=(int *)malloc(m2*n2*sizeof(int));
        c=(int *)malloc(m1*n2*sizeof(int));
        if(m1==m2&&n1==n2){
            printf("Enter the values of first matrix: ");
            a=getdata(m1,n1);
            printf("Enter the values of second matrix: ");
            b=getdata(m2,n2);
            for(i=0;i<m1;i++){
                    for(j=0;j<n1;j++){
                        c[i * n1 + j] = a[i * n1 + j] + b[i * n2 + j];
                    }
                }
            printf("The sum of the Matrix: ");
            display(c,m1,n1);
        }
        else
            printf("The matrix cannot be added\n");
    }while(m1!=m2&&n1!=n2);
}
void sub(){
    int m1,m2,n1,n2;
    int *a,*b,*c;
    int i,j;
    do{
        printf("Enter the no.of rows and columns of matrix 1:");
        scanf("%d%d",&m1,&n1);
        printf("Enter the no.of rows and columns of matrix 2:");
        scanf("%d%d",&m2,&n2);
        a=(int *)malloc(m1*n1*sizeof(int));
        b=(int *)malloc(m2*n2*sizeof(int));
        c=(int *)malloc(m1*n2*sizeof(int));
        if(m1==m2&&n1==n2){
            printf("Enter the values of first matrix: ");
            a=getdata(m1,n1);
            printf("Emter the values of second matrix: ");
            b=getdata(m2,n2);
            for(i=0;i<m1;i++){
                for(j=0;j<n2;j++){
                    c[i*n1+j]=a[i*n1+j]-b[i*n1+j];
                }
            }
            printf("The difference of the Matrix: ");
            display(c,m1,n1);
        }
        else
            printf("The matrix cannot be subracted\n");
    }while(m1!=m2&&n1!=n2);
}
void multiply(){
    int m1,m2,n1,n2;
    int *a,*b,*c;
    int i,j;
    do{
        printf("Enter the no.of rows and columns of matrix 1:");
        scanf("%d%d",&m1,&n1);
        printf("Enter the no.of rows and columns of matrix 2:");
        scanf("%d%d",&m2,&n2);
        a=(int *)malloc(m1*n1*sizeof(int));
        b=(int *)malloc(m2*n2*sizeof(int));
        c=(int *)malloc(m1*n2*sizeof(int));
        if(m2==n1){
            printf("Enter the values of first matrix: ");
            a=getdata(m1,n1);
            printf("Emter the values of second matrix: ");
            b=getdata(m2,n2);
            for(i=0;i<m1;i++){
                for(j=0;j<n2;j++){
                    c[i*j+n1]=0;
                    for(int k=0;k<n1;k++){
                        c[i*n1+j]*=a[i*n1+k]+b[k*n2+j];
                    }
                }
            }
            printf("The sum of the Matrix: ");
            display(c,m1,n1);
        }
        else
            printf("The matrix cannot be multiplied\n");
    }while(n1!=m2);
}
void display(int *mat,int m,int n){
    int i,j;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i*n+j]);
        }
    }
    printf("\n");
}