#include<stdio.h>
#include<stdlib.h>
#define size 5

void enqueue_front(int);
void enqueue_rear(int);

void dequeue_front();
void dequeue_rear();

void display();

int front=-1,rear=-1;
int queue[size];

int main()
{
    int ch,n;
    char ch1;
    
    do
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit \n");
        printf("\nEnter Your Choice  :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter the Number To Be Inserted In the Queue\n");
            scanf("%d",&n);

            printf("\na.Insert From Rear \nb.Insert From Front");
            printf("\nFrom Where You Want To Enter :: \n");
            scanf(" %c",&ch1);

            switch(ch1)
            {
                case 'a':
                enqueue_rear(n);
                break;

                case 'b':
                enqueue_front(n);
                break;

                default:
                printf("\nInvalid Input\n");
                break;
            }

            break;

            case 2:
            printf("\na.Delete From Rear \nb.Delete From Front");
            printf("\nFrom Where You Want To Delete :: \n");
            scanf(" %c",&ch1);

            switch(ch1)
            {
                case 'a':
                dequeue_rear();
                break;

                case 'b':
                dequeue_front();
                break;

                default:
                printf("\nInvalid Input\n");
                break;
            }

            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);

            default:
            printf("\nInvalid Choice Please Recheck And Choose Accordingly\n");
            break;
        }

    }while(ch!=4);
    
    return 0;
}

void enqueue_front(int x)
{
    if((rear+1)%size==front)
    {
        printf("\nQueue Is Full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[front]=x;
    }
    else if(front==0)
    {
        front=size-1;
        queue[front]=x;
    }
    else
    {
        front--;
        queue[front]=x;
    }

    display();
}

void enqueue_rear(int x)
{
    if((rear+1)%size==front)
    {
        printf("\nQueue Is Full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if(rear==size-1)
    {
        rear=0;
        queue[rear]=x;
    }
    else 
    {
        rear++;
        queue[rear]=x;
    }

    display();
}

void dequeue_front()
{
    if(front==-1 && rear==-1)
    {
        printf("\nThe Queue Is Empty\n");
    }
    else if(front==rear)
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[front]);
        front=rear=-1;
    }
    else if(front==size-1)
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[front]);
        front=0;
    }
    else
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[front]);
        front++;
    }

    display();

}

void dequeue_rear()
{
    if(front==-1 && rear==-1)
    {
        printf("\nThe Queue Is Empty\n");
    }
    else if(front==rear)
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[rear]);
        front=rear=-1;
    }
    else if(rear==0)
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[front]);
        rear=size-1;
    }
    else
    {
        printf("\nThe Deleted Number Is :: %d\n",queue[rear]);
        rear--;
    }

    display();
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