#include<stdio.h>

int main()
{
    int n,i;
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

    bubble_sort(a,n);

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

void bubble_sort(int arr[],int len)
{
    int temp,i,j;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j+1]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}