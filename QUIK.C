#include<stdio.h>
#include<conio.h>
void qsort(int [],int ,int);
int n;
void main()
{
  int a[50],i;
  char ch='y';
  while(ch=='y')
  {
   clrscr();
   printf("Enter no.of elements : ");
   scanf("%d",&n);
   printf("Enter the elements of array : ");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   printf("Passes are : \n");
   qsort(a,0,n-1);
   printf("The sorted elements are : ");
   for(i=0;i<n;i++)
   printf(" %d",a[i]);
   printf("\n do you want to sort again?");
   printf("\n Enter your choice y/n");
   scanf(" %c",&ch);
   }
  }
  void qsort(int a[],int lb,int ub)
  {
    int i,j,pivot,temp;
    if(lb<ub)
    {
     i=lb,j=ub,pivot=a[lb];
     while(i<j)
     {
      i++;
      while(a[i]<pivot&&i<=ub)
      i++;
      while(a[j]>pivot&&j>=lb)
      j--;
      if(i<j)
      {
       int t=a[i];
       a[i]=a[j];
       a[j]=t;
      }
     }
     temp=a[lb];
     a[lb]=a[j];
     a[j]=temp;
     for(i=0;i<n;i++)
     printf(" %d",a[i]);
     printf("\n");
     qsort(a,lb,j-1);
     qsort(a,j+1,ub);
     }
  }

