#include<stdio.h>
#include<stdlib.h>
#define size 5

void enqueue(int);
int dequeue();
void display();

int queue[size];
int front=-1;
int rear=-1;

int main()
{
    int ch, n,x;
    do
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter The Number To be Inserted in the queue :: ");
            scanf("%d",&n);
            enqueue(n);
            break;

            case 2:
            x=dequeue();
            printf("\nDeleted number Is :: %d \n",x);
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("\nYour Choice Seems To Be Incorrect Please Review It\n");
            break;

        }
    }while(ch!=4);
    return 0;
}

void enqueue(int n)
{
    if((rear+1)%size==front)
    printf("\nQueue Is Full Sorry Number Cannot be Inserted\n");

    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=n;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=n;
    }

    display();

}

int dequeue()
{
    int x;
    if(front==-1)
    {
        printf("\nQueue Is Empty\n");
    }
    else if(front == rear)
    {
        x=queue[front];
        front=rear=-1;
        return x;
    }
    else
    {
        x=queue[front];
        front=(front+1)%size;
        return x;
    }

}

void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue Is Empty ");
    }
    else
    {
        i=front;

        printf("\n\t ELEMENTS IN QUEUE ARE \n");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d ",queue[i]);
    }
}