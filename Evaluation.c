//Evaluation of Postfix and Prefix Expressions
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 100
void evalpost(char exp[]);
void evalpre(char exp[]);
int stack[max];
int top=-1;
void push(int ch){
    stack[++top]=ch;
}
int pop(){
    return stack[top--];
}
void evalpost(char exp[]){
    int i,op1,op2,val;
    for(i=0;i<strlen(exp);i++){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            op2=pop();
            op1=pop();
            switch(exp[i]){
                case '+':
                    val=op1+op2;
                    break;
                case '-':
                    val=op1-op2;
                    break;
                case '*':
                    val=op1*op2;
                    break;
                case '/':
                    val=op1/op2;
                    break;
                case '%':
                    val=op1%op2;
                    break;
                case '$':
                    val=pow(op1,op2);
                    break;
            }
            push(val);
        }
    }
    printf("The value of the expression is: %d\n",pop());
}
void evalprefix(char exp[]){
    int i,op1,op2,val;
    for(i=strlen(exp)-1;i>=0;i--){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            op1=pop();
            op2=pop();
            switch(exp[i]){
                case '+':
                    val=op1+op2;
                    break;
                case '-':
                    val=op1-op2;
                    break;
                case '*':
                    val=op1*op2;
                    break;
                case '/':
                    val=op1/op2;
                    break;
                case '%':
                    val=op1%op2;
                    break;
                case '$':
                    val=pow(op1,op2);
                    break;
            }
            push(val);
        }
    }
    printf("The value of the expression is: %d\n",pop());
}
void main(){
    int option;
    char exp[max];
    do{
        printf("1.Postfix Evaluation\n2.Prefix Evaluation\n3.Exit\n");
        printf("Enter your option: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter the postfix expression: ");
                scanf("%s",exp);
                evalpost(exp);
                break;
            case 2:
                printf("Enter the prefix expression: ");
                scanf("%s",exp);
                evalprefix(exp);
                break;
        }
    }while(option!=3);
}