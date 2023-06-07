//Parenthesis Check
#include <stdio.h>
#include <string.h>
#define max 100
int s[max],top=-1;
void push(char val);
char pop();
void main(){
    int flag=0;
    char exp[max];
    printf("Enter the expression: ");
    scanf("%s",exp);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(top==-1)
                flag=1;
            else{
                int symb=pop();
                if((symb=='('&&exp[i]==')')||(symb=='{'&&exp[i]=='}')||(symb=='['&&exp[i]==']'))
                    continue;
                else
                    flag=1;
            }
        }
    }
    if(top!=-1)
        flag=1;
    if(flag==0)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");
}
void push(char c){
    s[++top]=c;
}
char pop(){
    return s[top--];
}