#include <stdio.h>
#define max 5
void main(){
    int a[max],num,i,temp,;
    printf("Enter the no.of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<num;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("Sorted array: ");
    for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
}
