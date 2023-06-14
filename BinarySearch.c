#include <stdio.h>
#define max 5
void main(){
    int a[max],num,i,loc,target,flag=0,high,low;
    printf("Enter the no.of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter target: ");
    scanf("%d",&target);
    low=0;high=num-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(a[mid]==target){
            loc=mid;
            flag=1;
            break;
        }
        else if(a[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    if(flag)
        printf("Element found at %d\n",loc);
    else
        printf("Element not found\n");
}
