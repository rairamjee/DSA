#include<stdio.h>

int main()
{
    int n,i,b=0;
    int a[10];
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    printf("Enter the elements in the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Entered elements are :\n");
    display(a,n);

    merge_sort(a,b,n);

    printf("\nThe Sorted List Is :\n");
    display(a,n);
    return 0;
}

void display(int arr[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}

void merge_sort(int arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[],int lb,int mid,int ub)
{
    int b[ub];
    int i,j,k;
    k=lb;
    i=lb;
    j=mid+1;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k++]=arr[i++];
        }
        else
        {
            b[k++]=arr[j++];
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k++]=arr[j++];   
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k++]=arr[i++];   
        }
    }

    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
}
