#include<stdio.h>

int main()
{
    int arr[10];
    int n,i,sno,p;
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    printf("\tEnter the Elements in the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\tYour Entered Elements are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nEnter the elements to be searched in the list\n");
    scanf("%d",&sno);

    p=linear(arr,sno,n);

    if(p>0)
    {
        printf("\nYour Request For The Number %d Is Found At The Position %d\n",sno,p+1);
    }
    else
    printf("\nSorry, Number Is Not Found In The List\n");
    return 0;
}

int linear(int a[],int s,int l)
{
    int i,pos=-1;
    for(i=0;i<l;i++)
    {
        if(a[i]==s)
        {
            pos=i;
            break;
        }
    }
    return pos;
}