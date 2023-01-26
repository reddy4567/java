#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define size 10
int ch;
void menu()
{
  printf("Enter the option 1.Search/Insert 2.Display 3.Exit...");
  scanf("%d",&ch);
};
struct node
{
 int no;
 struct node *link;
};
void main()
{
 int i,loc,key;
 struct node *p,*ptr,*h[size];
 for(i=0;i<size;i++)
     h[i]=NULL;
 clrscr();
 menu();
 while(ch<3)
 {
  switch(ch)
   {
      case 1: printf("Enter a key to search:\n");
	      scanf("%d",&key);
	      loc = key%size;
	      ptr=h[loc];
	      if(h[loc]==NULL)
		{
		   struct node* p = (struct node*)malloc(sizeof(struct node));
		   p->no=key;
		   p->link=NULL;
		   h[loc]=p;
		}
	      else
	       {
		 ptr=h[loc];
		 while(ptr!=NULL && key!=ptr->no)
		       ptr=ptr->link;
		 if(ptr==NULL)
		   {  struct node* p = (struct node*)malloc(sizeof(struct node));
		      printf("Key not found in the table and done the insertion");
		      p->no=key;
		      p->link=NULL;
		      p->link=h[loc];
		      h[loc]=p;
		   }
		  else
		    printf(" Number already in the table\n");
	       }
	       menu(); break;
      case 2:
	      printf("The Contents of hash table are:\n");
	      for(i=0;i<size;i++)
	      {
		ptr=h[i];
		printf("%d---->",i);
		while(ptr!=NULL)
		 {
		    printf("%d ",ptr->no);
		    ptr=ptr->link;
		 }
	      printf("\n");
	      }
	      menu(); break;
       }
   }
}