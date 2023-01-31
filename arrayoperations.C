  #include<stdio.h>
  void insertion ();
  void deletion();
  void display();
  void menu();
  int n,i,j,item,ub,lb,ch,a[30],item;

  void main()
  {
  lb=ub=-1;
  clrscr();
  printf("Enter size of the list : ");
  scanf("%d",&n);
  menu();
  while(ch<4)
  {
  switch(ch) {
  case 1 : insertion(); break;
  case 2 : deletion();break;
  case 3 : display();break;
    }
    menu();
  }
 }
 void menu()
 {
 printf("1.insertion 2.deletion 3.display 4.exit\n");
 printf("Enter your choice : ");
 scanf("%d",&ch);
 }
 void insertion()
 {
 printf("Enter item to be inseted : ");
 scanf("%d",&item);
 if(ub==n-1)
 { printf("list is overflow\n"); return; }
 if(ub==-1)
 { ub=lb=0;
 a[lb]=item;return;}
 i=ub;
 while(i>-1&&a[i]>item)
 {
 a[i+1]=a[i];
 i=i-1; }
 a[i+1]=item;
 ub=ub+1;
 }
 void deletion()
 {
 if(lb==-1)
 {
 printf("list is underflow\n");return;}
 printf("Enter item to be deleted : " );
 scanf("%d",&item);
 if(lb==ub&&a[lb]==item)
 { lb=ub=-1; return; }
 i=lb;
 while(i<=ub&&a[i]<item)
 { i=i+1; }
 if(i==ub+1||a[i]>item)
 {
 printf("Element not found in the list\n ");return;}
 for(j=i;j<n-1;j++)
 {
 a[j]=a[j+1]; }
 ub=ub-1;
 }
 void display()
 {
 if(lb==-1)
 {
 printf("list is empty\n");return;}
 printf("Elements in the list are : ");
 for(i=lb;i<=ub;i++)
 {
 printf("%d ",a[i]); }
 printf("\n");
 }


