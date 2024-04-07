#include<stdio.h>
#include<stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes*prev;
    struct nodes*next;
}node;

void insert_at_beg();
void insert_at_anypos();
void insert_at_end();

void del_at_beg();
void del_at_anypos();
void del_at_end();

void display();

node*start=NULL;

int main()
{
    int ch;
    do
    {
        printf("\n1.INSERTION \n2.DELETION \n3.DISPLAY \n4.EXIT\n");
        scanf("%d",&ch);

        switch(ch)
        {
            int ch1;
            case 1:
            printf("\n1.Insert In Begining \n2.Insert At Any Position \n3.Insert At End\n");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                insert_at_beg();
                break;

                case 2:
                insert_at_anypos();
                break;

                case 3:
                insert_at_end();
                break;

                default:
                printf("\nENTER A VALID\n");
            }
            break;

            case 2:
            printf("\n1.Delete From Begining \n2.Delete From Any Position \n3.Delete From End\n");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                del_at_beg();
                break;

                case 2:
                del_at_anypos();
                break;

                case 3:
                del_at_end();
                break;

                default:
                printf("\nENTER A VALID\n");
            }
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("\nSORRY , ENTER A VALID CHOICE\n");
        }
        
    } while (ch!=4);
    
}

void insert_at_beg()
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Value :: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    
    display();

}

void insert_at_anypos()
{
    node*temp,*p;
    int x=1,n;
    p=start;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Position \n");
    scanf("%d",&n);
    printf("\nEnter the Value :: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;

    while(x<n-1 && p->next!=NULL)
    {
        p=p->next;
        ++x;
    }
    temp->next=p->next;
    temp->prev=p;
    p->next->prev=temp;
    p->next=temp;

    display();

}

void insert_at_end()
{
    node*temp,*p;
    p=start;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Value :: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }

    display();
}

void del_at_beg()
{
    node*temp;
    if(start==NULL)
    {
        printf("\nThe List Is Empty\n");
    }
    else
    {
        temp=start;
        printf("\nThe Deleted Value is :: %d \n",temp->data);
        start=start->next;
        temp->next=NULL;
        start->prev=NULL;
    }

    display();
}

void del_at_anypos()
{
    node*temp,*p;
    int x=1,n;
    p=start;

    printf("\nEnter the position ::\n");
    scanf("%d",&n);
    while(x<n-1 && p->next!=NULL)
    {
        p=p->next;
        ++x;
    }
    temp=p->next;
    printf("\nThe Deleted Value is :: %d \n",temp->data);
    temp->next->prev=temp->prev;
    p->next=temp->next;
    temp->next=NULL;
    temp->prev=NULL;

    display();
}

void del_at_end()
{
    node*temp,*p;
    p=start;
    if(start==NULL)
    {
        printf("\nThe List Is Empty\n");
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp=p;
        printf("\nThe Deleted Value is :: %d \n",temp->data);
        p->prev->next=NULL;
        temp->prev=NULL;
    }

    display();
}

void display()
{
    node*temp;
    if(start==NULL)
    {
        printf("\nThe List Is Empty\n");
    }
    else
    {
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}