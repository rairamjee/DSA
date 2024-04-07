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

    insertion_sort(a,n);

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

void insertion_sort(int arr[],int len)
{
   int i,j,temp;

   for(i=1;i<len;i++)
   {
    temp=arr[i];
    j=i-1;
    {
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
   }
}