#include <stdio.h>
#define max 5
void main(){
    int a[max],num,i,loc,target,flag=0;
    printf("Enter the no.of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter target: ");
    scanf("%d",&target);
    for(i=0;i<num;i++){
        if(a[i]==target){
            loc=i;
            flag=1;
            break;
        }
    }
    if(flag)
        printf("Element found at %d\n",loc);
    else
        printf("Element not found\n");
}
