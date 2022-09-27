#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node* llink;
    struct node* rlink;
};
struct node *root;
int n=0;
void insertf()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    int d;
    printf("Enter the data:");
    scanf("%d",&d);
    temp->data=d;
    temp->llink=temp->rlink=NULL;
    if (root==NULL)
    {
        root=temp;
        n+=1;
        return;
    }
    else
    {
        root->llink=temp;
        temp->rlink=root;
        root=temp;
        n+=1;
        return;
    }
}
void insert()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    int d,key;
    printf("Enter the data:");
    scanf("%d",&d);
    temp->data=d;
    temp->llink=temp->rlink=NULL;
    if (root==NULL)
    {
        printf("The ds is empty,enter elements before");
        return;
    }
    printf("Enter key to which left of u want to insert");
    scanf("%d",&key);
    if (key==root->data)
    {
        temp->rlink=root;
        root->llink=temp;
        root=temp;
        n+=1;
        return;
    }
    struct node *prev,*next;
    next=root;
    while(next!=NULL)
    {
        if (key==next->data)
            break;
        next=next->rlink;
    }
    prev=next->llink;
    if (next!=NULL)
    {
        temp->rlink=next;
        temp->llink=prev;
        prev->rlink=temp;
        next->llink=temp;
        n+=1;
        return;
    }
    printf("Key not present");

}
void delete()
{
    int key;
    struct node *prev,*next,*temp;
    printf("Enter the key to be deleted");
    scanf("%d",&key);
    next=root;
    if (key==root->data && n!=1)
    {
        next=root->rlink;
        next->llink=NULL;
        free(root);
        root=next;
        n-=1;
        return;
    }
    else if (key==root->data && n==1)
    {
        free(root);
        root=NULL;
        return;
    }
    while(next!=NULL)
    {
        if(key==next->data)
            break;
        next=next->rlink;
    }
    if(next!=NULL && next->rlink!=NULL)
    {
        prev=next->llink;
        temp=next;
        next=next->rlink;
        next->llink=prev;
        prev->rlink=next;
        free(temp);
        return;
    }
    else if(next->rlink==NULL &&key==next->data)
    {
        prev=next->llink;
        prev->rlink=NULL;
        free(next);
        return;
    }
    printf("Key not found!");
}
void display()
{
    struct node *temp;
    if (root==NULL)
    {
        printf("Empty!");
        return;
    }
    temp=root;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->rlink;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n Enter choice:");
        printf("1.Insert front\n2.Insert any\n3.Display\n4.Delete");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
             insertf();
             break;
            case 2:
             insert();
             break;
            case 3:
             display();
             break;
            case 4:
             delete();
             break;
            default:
             exit(0);
        }
    }
}
