#include<stdio.h>
#include<conio.h>
void main()
{
   char t[50],p[10];
   int i,j,m,n;
   clrscr();
   printf("Enter the text without blank spaces : ");
   scanf("%s",&t);
   printf("Enter the pattern without blank spaces : ");
   scanf("%s",&p);
   for(m=0;p[m]!='\0';m++);
   for(i=0;i<=n-m;i++)
   {
    j=0;
    while(j<m&&p[j]==t[i+j])
     j++;
    if(j==m)
    {
      printf("Pattern is found at %d",j);
      return;
    }
   }
   printf("Pattern not found");
}