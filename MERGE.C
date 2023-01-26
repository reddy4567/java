#include<stdio.h>
#include<stdlib.h>
typedef struct slist
{
    int no;
    struct slist *next;
}node;
node *l1=NULL,*l2=NULL,*l3=NULL;

node* create(node *f);
node* merge(node *a,node *b);
void dis(node *ptr);
void main()
{   node *v;
   int ch,item;
   printf("Enter first linked list : ");
   l1=create(l1);
   printf("\nEnter second linked list : ");
   l2=create(l2);
   printf("\nThe first list is : ");
   dis(l1);
   printf("\nThe second list list is : ");
   dis(l2);
   l3=merge(l1,l2);
   printf("\nThe result list is : ");
   dis(l3);
   getch();
}
node *create(node *f)
{
  node *p,*ptr,*save;
  int item;
  char ch='y';
  do
  {
  p=malloc(sizeof(node));
   printf("\nEnter element to insert : ");
   scanf("%d",&p->no);
   p->next=NULL;
   if(f==NULL)
   {
     f=p;ptr=f;
   }
   else if(p->no<=f->no)
   {
    p->next=f;
    f=p;
   }
   else
   {
    save=f;ptr=f->next;
    while(ptr!=NULL&&ptr->no<p->no)
    {
     save=ptr;
     ptr=ptr->next;
     }
     save->next=p;
     p->next=ptr;
   }
   printf("do you want to insert another element y/n :");
   scanf(" %c",&ch);
  }while(ch=='y');
  return f;
}
void dis(node *ptr)
{
  if(ptr==NULL)
  {
   printf("Empty");
   return;
   }
   while(ptr!=NULL)
   {
     printf("%d ",ptr->no);
     ptr=ptr->next;
   }
   printf("\n");
}
node* merge(node *a,node *b)
{
 node *p,*f=NULL,*ptr;
 if(a==NULL)
 return b;
 if(b==NULL)
 return a;
 while(a!=NULL&&b!=NULL)
 {
   p=malloc(sizeof(node));
   if(a->no<b->no)
   {
    p->no=a->no;
    a=a->next;
    p->next=NULL;
   }
   else
   {
    p->no=b->no;
    b=b->next;
    p->next=NULL;
   }
   if(f==NULL)
   {
    f=p;
    ptr=f;
   }
   else
   {
    ptr->next=p;
    ptr=p;
    }
  }
  if(a==NULL)
  {
   while(b!=NULL)
   {
    p=malloc(sizeof(node));
    p->no=b->no;
    p->next=NULL;
    ptr->next=p;
    ptr=p;
    b=b->next;
   }
  }
  else
  {
   while(a!=NULL)
   {
      p=malloc(sizeof(node));
      p->no=a->no;
      p->next=NULL;
      ptr->next=p;
      ptr=p;
      a=a->next;
   }
   }
   return f;
 }