//Shell sort
#include <stdio.h>
#define max 20
void main(){
    int a[max],i,j,n,temp,gap,swapped;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    do{
        do{
           swapped = 0;
           for(i=0;i<n-1;i++){
               if(a[i]>a[i+1]){
                   temp = a[i];
                   a[i] = a[i+1];
                   a[i+1] = temp;
                   swapped = 1;
               }
           }
        }while(swapped==1);
        gap = gap/2;
    }while(gap>=1);
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
