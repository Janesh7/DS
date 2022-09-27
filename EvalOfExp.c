#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[50];
int top=-1;
int isdig(char symbol)
{
    int p=0;
    if (symbol>='0'&&symbol<='9')
        p=1;
    return p;
}
void push(char symbol)
{
    stack[++top]=symbol;
}
int pop()
{
    return stack[top--];
}
int op(int a,int b,char op)
{
    int r;
    if (op=='+')
        r=a+b;
    else if (op=='-')
        r=a-b;
    else if (op=='*')
        r=a*b;
    else if (op=='/')
        r=a/b;
    return r;
}
int main()
{
    char exp[40];
    char a,b,r;
    gets(exp);
    int i;
    for(i=0;i<strlen(exp);i++)
    {
        if (isdig(exp[i]))
            push(exp[i]-'0');
        else{
            a=pop();
            b=pop();
            r=op(b,a,exp[i]);
            push(r);
        }
    }
    printf("%d",pop());
}
