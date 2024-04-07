#include<stdio.h>
#include<stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes * prev;
    struct nodes * next;
}node;

void insert_at_beig();
void insert_at_anypos();
void insert_at_end();

void del_at_beig();
void del_at_anypos();
void del_at_end();

void display();

node *head=NULL;
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
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

    if(head==NULL)
    {
        head=temp;
        tail=temp;
        head->next=head;
        head->prev=head;
    }
    else
    {
        temp->next=head;
        temp->prev=head->prev;
        head->prev=temp;
        tail->next=temp;
        head=head->prev;
    }

    display();

}

void insert_at_anypos()
{
    node *temp,*p;
    int n,x=1;

    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

    printf("\nEnter the position :: ");
    scanf("%d",&n);

    p=head;

    while(p->next != head && x<n-1)
    {
        p=p->next;
        x++;
    }
    temp->next=p->next;
    p->next->prev=temp;
    temp->prev=p;
    p->next=temp;

    display();

}

void insert_at_end()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the Number :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

    if(head==NULL)
    {
        head=temp;
        tail=temp;
        head->next=head;
        head->prev=head;
    }
    else
    {
        temp->next=head;
        temp->prev=tail;
        tail->next=temp;
        head->prev=temp;
        tail=tail->next;
    }

    display();

}

void del_at_beig()
{
    node *temp;
    if(head==NULL)
    {
        printf("\nSorry, The List Is Empty");
    }
    else
    {
        temp=head;
        if(head->next==head)
        {
            printf("\nThe deleted value is :: %d\n",temp->data);
            temp->next=NULL;
            temp->prev=NULL;
            head=NULL;
            tail=NULL;
        }
        else
        {
            head=head->next;
            tail->next=head;
            head->prev=tail;
            temp->next=NULL;
            temp->prev=NULL;
            printf("\nThe deleted value is :: %d\n",temp->data);
        }
    }

    display();

}

void del_at_anypos()
{
    node *temp,*p;
    int n,x=1;
    printf("\nEnter the position :: ");
    scanf("%d",&n);

    p=head;

    while(p->next != head && x<n-1)
    {
        p=p->next;
        x++;
    }
    temp=p->next;
    temp->next->prev=p;
    p->next=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
    printf("\nThe Deleted Value Is :: %d\n",temp->data);

    display();

}

void del_at_end()
{
     node *temp;
    if(head==NULL)
    {
        printf("\nSorry, The List Is Empty");
    }
    else
    {
        temp=tail;
        if(head->next==head)
        {
            printf("\nThe deleted value is :: %d\n",temp->data);
            temp->next=NULL;
            temp->prev=NULL;
            head=NULL;
            tail=NULL;
        }
        else
        {
            tail=tail->prev;
            tail->next=head;
            head->prev=tail;
            temp->next=NULL;
            temp->prev=NULL;
            printf("\nThe deleted value is :: %d\n",temp->data);
        }
    }

    display();
}

void display()
{
    node *temp;
    if(head==NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        temp=head;
        while(temp->next != head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}