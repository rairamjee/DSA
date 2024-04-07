#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct{
    int a[max];
    int f;
    int r;
}queue;

void insert(queue*);
void del(queue*);
void display(queue*);

queue que;
int main()
{
    que.f=-1;
    que.r=-1;
    int ch;

     do{
    printf("\nEnter 1 for Insertion In the Queue\n");
    printf("Enter 2 for Deletion In the Queue\n");
    printf("Enter 3 for Display of the elements in the Queue\n");
    printf("Enter 4 for Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        insert(&que);
        break;

        case 2:
        del(&que);
        break;

        case 3:
        display(&que);
        break;

        case 4:
        exit(0);
        
        default:
        printf("\n Sorry, Your Request is out of service \n Please input a valid choice\n\n2");
    }
    }while(ch!=4);
    return 0;
}

void insert(queue*p)
{
    int n;
    if(p->r==max-1)
    {
        printf("\nQUEUE OVERFLOW\n");
        display(&que);
    }
    else
    {
        printf("\nEnter the number to be added in the queue :: ");
        scanf("%d",&n);
        if(p->f==-1 && p->r==-1)
        {
            p->f=0;
            p->r=0;
        }
        else
        {
            p->r++;
        }
        p->a[p->r]=n;
    }
}

void del(queue*p)
{
    if(p->r==-1)
    {
    printf("\nQUEUE UNDERFLOW");
    }

    else
    {
        printf("The deleted  number is %d from %d position \n",p->a[p->f],p->f+1);
        if(p->f==p->r)
        {
            p->f=-1;
            p->r=-1;
        }
        else
        {
            p->f++;
        }
    }
}

void display(queue*p)
{
    int i;
    if(p->r==-1)
    {
        printf("\nQUEUE UNDERFLOW\n");
    }
    else
    {
        for(i=p->f;i<=p->r;i++)
        {
            printf("%d ",p->a[i]);
        }
    }
}