#include <stdio.h>
#define max 5
void main(){
    int a[max],num,i,temp;
    printf("Enter the no.of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<num;i++){
        for(int j=0;j<num-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
}
