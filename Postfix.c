//Infix to Postfix Conversion
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define max 100
char s[max],postfix[max];
int top=-1;
int isFull(){
    return top==max-1;
}
int isEmpty(){
    return top==-1;
}
void push(char ch){
    s[++top]=ch;
}
char pop(){
    return s[top--];
}
char peek(){
    return s[top];
}
int prec(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '$':
            return 4;
    }
    return -1;
}
int infixtopostfix(char *exp){
    int i,k=0,symb;
    for(i=0;i<strlen(exp);i++){
        if(isalnum(exp[i]))
            postfix[k++]=exp[i];
        else if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            while(!isEmpty()&&peek()!='('){
                symb=pop();
                postfix[k++]=symb;
            }
            symb = pop();
        }
        else{
            while(!isEmpty()&&prec(exp[i])<=prec(peek())){
                symb=pop();
                postfix[k++]=symb;
            }
            push(exp[i]);
        }
    }
    while(!isEmpty())
        postfix[k++]=pop();
    postfix[k]='\0';
    printf("The postfix expression is: %s\n",postfix);
}
void main(){
    char exp[max];
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    infixtopostfix(exp);
}