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

node*rear=NULL;
node*front=NULL;

int main()
{
    int ch;
    do
    {
        printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT\n");
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
            printf("\nSorry,Invalid Choice\n");
        }
    } while(ch!=4);
    
    return 0;
}

void push()
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("\nEnter the number  :: ");
    scanf("%d",&temp->data);
    temp->next=NULL;

    if(rear==NULL)
    {
        rear=temp;
        front=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
    display();
}

void pop()
{
    node*temp;
   if(rear==NULL)
   {
    printf("\nQUEUE UNDERFLOW\n");
   } 
   else
   {
    temp=front;
    printf("The Deleted Number is :: %d \n",temp->data);
    if(rear==front)
    {
        rear=NULL;
        front=NULL;
    }
    else
    {
        front=front->next;
        temp->next=NULL;
    }
   }
   display();
}

void display()
{
    node*temp;
    temp=front;
    if(rear==NULL)
    {
        printf("\nQUEUE UNDERFLOW\n");
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