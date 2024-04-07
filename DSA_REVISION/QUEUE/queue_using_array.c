#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int a[MAX],f=-1,r=-1;   // r is used for forward entry rear // f is used for deleting forward front

void insert();
void del();
void display();

int main()
{
    int ch;
    do{
    printf("Enter 1 for Insertion In the Queue\n");
    printf("Enter 2 for Deletion In the Queue\n");
    printf("Enter 3 for Display of the elements in the Queue\n");
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
        printf(" Sorry, Your Request is out of service \n Please input a valid choice\n\n2");
    }
    }while(ch!=4);
    return 0;
}

void insert()
{
    int no;
    if(r==MAX-1)
    {
        printf("\nQUEUE OVERFLOW\n");
        display();
    }
    else
    {
        if(r==-1 && f==-1)
        {
            r=0;
            f=0;
        }
        else
        {
            r++;
        }
        printf("\nEnter the number to be inserted into the Queue\n");
        scanf("%d",&no);
        a[r]=no;
    }
}

void del()
{
    if(r==-1)
    {
        printf("\nQUEUE UNDERFLOW\n");
    }
    else
    {
        printf("\nThe Deleted Number is %d from %d position \n\n",a[f],f+1);
        if(r==f)
        {
            f=-1;
            r=-1;
        }
        else
        f++;
    }
}

void display()
{
    int i;
    if(r==-1)
    {
        printf("\nQUEUE UNDERFLOW\n");
    }
    else
    {
        for(i=f;i<=r;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}