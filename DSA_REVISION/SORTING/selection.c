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

    selection_sort(a,n);

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

void selection_sort(int arr[],int len)
{
   int i,j,temp,min;
   for(i=0;i<len-1;i++)
   {
    min=i;
    for(j=i+1;j<len;j++)
    {
        if(arr[min]>arr[j])
        {
            min=j;
        }
    }
     if(min!=i)
        {
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
   }

}