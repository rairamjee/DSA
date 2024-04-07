#include<stdio.h>
#include<stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes*next;
}node;

void insert_at_beig();
void insert_at_anypos();
void insert_at_end();

void del_at_beig();
void del_at_anypos();
void del_at_end();

void display();

node *tail=NULL;

int main()
{
    int ch;
    char ch1;
    
    do
    {
        printf("\nEnter 1 for Insertion:");
        printf("\nEnter 2 for Deletion:");
        printf("\nEnter 3 for Display:");
        printf("\nEnter 4 for Exit:\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter a for insert at beigning");
            printf("\nEnter b for insert at any postion");
            printf("\nEnter c for insert at end\n");
            scanf(" %c",&ch1);
            switch(ch1)
            {
                case 'a':
                insert_at_beig();
                break;

                case 'b':
                insert_at_anypos();
                break;

                case 'c':
                insert_at_end();
                break;

                default:
                printf("\nEnter a valid Choice");
                break;
            }
            break;

        case 2:
            printf("\nEnter a for delete at beigning");
            printf("\nEnter b for delete at any postion");
            printf("\nEnter c for delete at end\n");
            scanf(" %c",&ch1);
            switch(ch1)
            {
                case 'a':
                del_at_beig();
                break;

                case 'b':
                del_at_anypos();
                break;

                case 'c':
                del_at_end();
                break;

                default:
                printf("\nEnter a valid Choice");
                break;
            }
            break;

        case 3:
            display();
            break; 
        
        case 4:
            exit(0);

        
        default:
            printf(" Sorry, Your Request is out of service \n Please input a valid choice\n\n2");
            break;
        }
    }while(ch!=4);
    return 0;
}

void insert_at_beig()
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(tail==NULL)
    {
       tail=temp;
       tail->next=temp;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
    }

    display();
}

void insert_at_anypos()
{
    node*temp,*p;
    int n,x=1;

    printf("\nEnter A  Valid Position :");
    scanf("%d",&n);
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    p=tail->next;
    while(x<n-1)
    {
        p=p->next;
        x++;
    }
    temp->next=p->next;
    p->next=temp;

    display();
}

void insert_at_end()
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(tail==NULL)
    {
       tail=temp;
       tail->next=temp;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }

    display();
}

void del_at_beig()
{
    node*temp;
    if(tail==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        temp=tail->next;
        printf("\nThe deleted value is : %d \n",temp->data);
        if(tail->next==tail)
        {
            temp->next=NULL;
            tail=NULL;
        }
        else
        {
            tail->next=temp->next;
            temp->next=NULL;
        }
    }

    display();
}

void del_at_anypos()
{ 
    node*temp,*p;
    int n,x=1;
    if(tail==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        temp=tail->next;
        printf("\nEnter the position :");
        scanf("%d",&n);

        while(x<n-1)
        {
            temp=temp->next;
            x++;
        }
        p=temp->next;
        printf("\nThe Deleted Value is : %d \n",p->data);
        temp->next=p->next;
        p->next=NULL;
    }
    display();
}

void del_at_end()
{
    node*temp;
    if(tail==NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        temp=tail->next;
        printf("\nThe deleted value is : %d \n",tail->data);
        if(tail->next==tail)
        {
            temp->next=NULL;
            tail=NULL;
        }
        else
        {
           while(temp->next->next!=tail->next)
           {
            temp=temp->next;
           }
           temp->next=tail->next;
            tail->next=NULL;
            tail=temp;
        }
    }  

    display();
}

void display()
{
    node*temp;
    if(tail==NULL)
    {
        printf("\nEmpty\n");
    }
    else
    {
        temp=tail->next;
        while(temp->next!=tail->next)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}