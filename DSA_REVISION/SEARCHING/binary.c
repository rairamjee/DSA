#include<stdio.h>

int main()
{
    int arr[10];
    int n,i,sno,p,x=0;
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

    p=binary(arr,sno,x,n);

    if(p>0)
    {
        printf("\nYour Request For The Number %d Is Found At The Position %d\n",sno,p+1);
    }
    else
    printf("\nSorry, Number Is Not Found In The List\n");
    return 0;
}

int binary(int a[],int s,int lb,int ub)
{
   int mid,pos=-1;
   while(lb<ub)
   {
    mid=(lb+ub)/2;
    if(a[mid]==s)
    {
        pos=mid;
        break;
    }
    if(a[mid]>s)
    ub=mid-1;
    else
    lb=mid+1;
   }
    return pos;
}