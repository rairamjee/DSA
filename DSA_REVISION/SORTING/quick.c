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

    quick_sort(a,b,n);

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

void quick_sort(int arr[],int lb,int ub)
{
    int mid;
    //printf("%d",lb);
    if(lb<ub)
    {
    mid=partition(arr,lb,ub);
    quick_sort(arr,lb,mid-1);
    quick_sort(arr,mid+1,ub);
    }
}

int partition(int arr[],int lb,int ub)
{
    int key,start,end,temp;
    key=arr[lb];
    start=lb;
    end=ub;

    while (start<end)
    {
        while (arr[start]<=key)
        {
            start++;
        }
        while (arr[end]>key)
        {
            end--;
        }
        if(start<end)
        {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }       
    } 
        temp=arr[lb];
        arr[lb]=arr[end];
        arr[end]=temp;

    return end;
}