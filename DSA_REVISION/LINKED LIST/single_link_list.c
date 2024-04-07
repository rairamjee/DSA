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


node*start=NULL;
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
            printf(" Sorry, Your Request is out of service \n Please input a valid choice\n\n");
            break;
        }
    }while(ch!=4);
    return 0;
}

void insert_at_beig()
{
    node *temp,*p;

    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the number  :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(start == NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        temp->next=p;
        start=temp;
    }

    display();
}

void insert_at_anypos()
{
    node *temp,*p;
    int n,x=1;

    printf("\nEnter the position  :: ");
    scanf("%d",&n);
    p=start;
    if(n==1)
    {
        printf("\nCall insert at beigning function\n");
    }
    else{
        temp=(node*)malloc(sizeof(node));
        printf("\nEnter the number :: ");
        scanf("%d",&temp->data);
        temp->next=NULL;

        while(x<n-1 && p->next!=NULL)
        {
            p=p->next;
            x++;
        }
        temp->next=p->next;
        p->next=temp;
    }

   display();
}

void insert_at_end()
{
    node *temp,*p;

    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(start == NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }

    display();
}

void del_at_beig()
{
    node*p;
    if(start==NULL)
    {
        printf("\nNo Elements in the List");
    }
    else
    {
        p=start;
        start=p->next;
        p->next=NULL;
        printf("\nThe deleted value is  : %d\n",p->data);

    }
    display();
}

void del_at_anypos()
{
    node *p,*temp;
    int n,x=1;
    printf("\nEnter the position ");
    scanf("%d",&n);

    p=start;
    while(x<n-1 && p->next->next!=NULL)
        {
            p=p->next;
            x++;
        }
        temp=p->next;
        p->next=temp->next;
        temp->next=NULL;
        printf("\nThe deleted value is  : %d\n",temp->data);


        display();

}

void del_at_end()
{
    node*p,*temp;
    if(start==NULL)
    {
        printf("\nNo Elements in the List");
    }
    else
    {
        p=start;
       while(p->next->next!=NULL)
       {
        p=p->next;
       }
       temp=p->next;
       p->next=NULL;
       printf("\nThe deleted value is  : %d\n",temp->data);

    }

    display();
}

void display()
{
    node*temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}