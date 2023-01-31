#include <stdio.h>
#include <conio.h>
void swap(int *a,int *b)
{
 int temp= *a;
 *a = *b;
 *b = temp;
}
void Heapify(int arr[],int n,int i)
{
 int largest = i;
 int left = 2*i+1;
 int right = 2*i+2;
 if(left<n && arr[left] > arr[largest])
  largest = left;
 if(right < n && arr[right] > arr[largest])
  largest = right;
 if (largest!=i)
 {
  swap (&arr[i],&arr[largest]);
  Heapify(arr,n,largest);
 }
}
void Heapsort(int arr[],int n)
{
 int i;
 for(i=((n/2)-1);i>=0;i--)
  Heapify(arr,n,i);
 for(i=n-1;i>=0;i--){
  swap(&arr[0],&arr[i]);
  Heapify(arr,i,0);
 }
}
void printArray(int arr[],int n)
{
 int i;
 for (i=0;i<n;i++)
  printf("%d ",arr[i]);
 printf("\n");
}
int main()
{
 int arr[10],n,i,j;
 clrscr();
 printf("Enter the size of the array: ");
 scanf("%d",&n);
 printf("Enter the elements: ");
 for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
 Heapsort(arr,n);
 printf("Sorted order is \n");
 printArray(arr,n);
 getch();
 return (0);
}