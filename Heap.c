#include<stdlib.h>
#include<stdio.h>
int heap[50];
int n=0;
void insert()
{
    int item,c,p;
    printf("item:");
    scanf("%d",&item);
    c=n;
    p=(c-1)/2;
    while (c!=0 && item>=heap[p])
    {
        heap[c]=heap[p];
        c=p;
        p=(c-1)/2;
    }
    heap[c]=item;
    n+=1;
}
void display()
{
    if (n==0)
    {
        printf("Empty!");
        return;
    }
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\n",heap[i]);
    }
}
void main()
{

    int ch;
    printf("Enter choice:");
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            default:
                exit(0);
        }
    }
}
