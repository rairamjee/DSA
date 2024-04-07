#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX],top=-1;
void insert();
void del();
void display();

int main()
{
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
        insert();
        break;

        case 2:
        del();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);
        
        default:
        printf(" Sorry, Your Request is out of service \n Please input a valid choice\n\n");
    }
    }while(ch!=4);
    return 0;
}

void insert()
{
    int no;
    if(top==MAX-1)
    {
        printf("\nSTACK OVERFLOW\n");
        display();
    }
    else
    {
        printf("\nEnter the number to be inserted into the Stack\n");
        scanf("%d",&no);
        a[++top]=no;
    }
}

void del()
{
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
        printf("\nThe Deleted Number is %d from %d position \n\n",a[top],top+1);
        top--;
    }
}

void display()
{
    int i;
    if(top==-1)
    printf("\nSTACK UNDERFLOW\n");

    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}