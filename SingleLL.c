#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root;
void insertf(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    int d;
    printf("Enter the data");
    scanf("%d",&d);
    temp->data=d;
    if (root==NULL)
    {
        root=temp;
    }
    else 
    {
        temp->link=root;
        root=temp;
    }
}

void inserte()
{
    struct node *temp,*prev;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    int d;
    printf("Enter the data");
    scanf("%d",&d);
    temp->data=d;
    if (root==NULL)
    {
        root=temp;
    }
    else 
    {
        prev=root;
        while(prev->link!=NULL)
        {
            prev=prev->link;
        }
        prev->link=temp;
    }
}

void del(){
    struct node *next,*prev,*temp;
    if (root==NULL){
        printf("Empty");
        return;
    }
    int key;
    printf("Enter the key to be removed");
    scanf("%d",&key);
    next=root;
    if (root->data==key)
    {
        root=root->link;
        free(next);
        return;
    }
    while (next!=NULL)
    {
        if (next->data==key)
            break;
        prev=next;
        next=next->link;
    }
    if (next!=NULL)
    {
        temp=next;
        next=next->link;
        prev->link=next;
        free(temp);
        return;
    }
    else if(next->data==key){
        prev->link=NULL;
        free(next);
        return;
    }
    else {
        printf("Not found ");
        return;
    }
}
void display(){
    struct node *temp;
    if (root==NULL)
    {
        printf("empty");
        return;
    }
    temp=root;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("Enter choice:");
        printf("1.Insert Front\n2.Display\n3.Insert end\n4.Delete\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            insertf();
            break;
        case 3:
            inserte();
            break;
        case 2:
            display();
            break;
        case 4:
            del();
            break;
        default:
            exit(0);
            break;
        }
    }
}
