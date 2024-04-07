#include<stdio.h>
#include<stdlib.h>

typedef struct nodes
{
    int data;
    struct nodes*next;
}node;

void push();
void pop();
void display();

node*top=NULL;

int main()
{
    int ch;
    do
    {
       printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT \n");
       scanf("%d",&ch);

       switch(ch)
       {
        case 1:
        push();
        break;

        case 2:
        pop();
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);

        default:
        printf("\nInvalid Choice, Enter a valid choice\n");
        break;
       }
    } while (ch!=4);
    
    return 0;
}

void push()
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the number  :: ");
    scanf("%d",&temp->data);
    temp->next=top;
    top=temp;
    display();
}

void pop()
{
    node*temp;
    if(top==NULL)
    {
        printf("\nSTACK UNDERFLOW\n");
    }
    else
    {
    temp=top;
    printf("\nThe deleted value is : %d\n",temp->data);
    if(top->next==NULL)
    {
        top=NULL;
    }
    else
    {
        top=top->next;
        temp->next=NULL;
    }
    }
    display();
}

void display()
{
    node*temp;
    temp=top;
    if(top==NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}