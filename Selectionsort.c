#include <stdio.h>
#define max 5
void main(){
    int a[max],num,i,temp,min;
    printf("Enter the no.of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<num-1;i++){
        min=i;
        for(int j=i+1;j<num;j++){
            if(a[j]<a[min]){
                min=j;
            }
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
        }
    }
    printf("Sorted array: ");
    for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
}
