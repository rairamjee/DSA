#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct{
    int a[max];
    int top;
}stack;

void insert(stack*);
void del(stack*);
void display(stack*);

stack stk;
    
int main()
{
    stk.top=-1;
    int ch;

    do{
    printf("\nEnter 1 for Insertion In the Stack\n");
    printf("Enter 2 for Deletion In the Stack\n");
    printf("Enter 3 for Display of the elements in the Stack\n");
    printf("Enter 4 for Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        insert(&stk);
        break;

        case 2:
        del(&stk);
        break;

        case 3:
        display(&stk);
        break;

        case 4:
        exit(0);
        
        default:
        printf(" Sorry, Your Request is out of service \n Please input a valid choice\n\n2");
    }
    }while(ch!=4);
    return 0;
}

void insert(stack*p)
{
    int n;
    if(p->top==max-1)
    {
        printf("\nSTACK OVERFLOW\n");
        display(&stk);
    }
    else
    {
        printf("\nEnter The number to be Inserted In The Stack :: ");
        scanf("%d",&n);
        p->a[++p->top]=n;
    }
}

void del(stack*p)
{
    if(p->top==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        printf("The Deleted number is  %d  from  %d  position",p->a[p->top],p->top+1);
        --p->top;
    }
}

void display(stack*p)
{
    int i;
    if(p->top==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        for(i=p->top;i>=0;i--)
        {
            printf("%d ",p->a[i]);
        }
    }
}