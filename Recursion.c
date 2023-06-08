//Recursion
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int);
int fibonacci(int);
int power(int, int);
int lcm(int, int);
int hcf(int, int);

void main(){
    int n,f;
    int choice;
    do{
        printf("List of Recursive Programs\n");
        printf("1. Factorial\n2. Fibonacci\n3. Power and Exponential of a Number\n4. LCM\n5. HCF\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("Enter a number to find its factorial: ");
                    scanf("%d", &n);
                    f = factorial(n);
                    printf("Factorial of %d is %d\n", n, f);
                    break;
            case 2: 
                    printf("Enter a number to find its fibonacci series: ");
                    scanf("%d", &n);
                    printf("Fibonacci series upto %d terms is: ", n);
                    for(int i=0;i<n;i++){
                        printf("%d ", fibonacci(i));
                    }
                    printf("\n");
                    break;
            case 3: 
                    printf("Enter base: ");
                    scanf("%d", &n);
                    printf("Enter exponent: ");
                    scanf("%d", &f);
                    printf("%d raised to the power %d is %d\n", n, f, power(n, f));
                    break;
            case 4: 
                    printf("Enter two numbers: ");
                    scanf("%d %d", &n, &f);
                    printf("LCM of %d and %d is %d\n", n, f, lcm(n, f));
                    break;
            case 5: 
                    printf("Enter two numbers: ");
                    scanf("%d %d", &n, &f);
                    printf("HCF of %d and %d is %d\n", n, f, hcf(n, f));
                    break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=6);
}
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return factorial(n-1)*n;
    }
}
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int power(int x, int y){
    if(y==0){
        return 1;
    }
    else{
        return x*power(x, y-1);
    }
}
int lcm(int x, int y){
    static int lm = 1;
    if(lm%x==0 && lm%y==0){
        return lm;
    }
    else{
        lm++;
        lcm(lm, y);
        return lm;
    }
}
int hcf(int x, int y){
    if(y!=0){
        return hcf(y, x%y);
    }
    else{
        return x;
    }
}