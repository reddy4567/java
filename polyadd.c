#include<stdio.h>
#include<stdlib.h>
typedef struct slist
{
int coff;
int exp;
struct slist *link;
}node;
void create(node **p);
void disp(node *p);
void add(node *p, node *q, node **r);
void create(node **p)
{ node *k;
char ch='y';
printf("Enter the first term of equation\n");
do
{
node *t;
t=(node *) malloc(sizeof(node));
printf("enter the coefficent...");
scanf("%d",&t->coff);
printf("enterthe exponent...");
scanf("%d",&t->exp);
if(*p==NULL)
{ *p=t;k=t;}
else
{ k->link=t;k=t;}
printf("do U want to enter the next term of the equation(y/n)..");
scanf(" %c",&ch);
}while(ch=='y');
k->link=NULL;
}
void disp(node *p)
{ node *t = p;
if(p==NULL)
{
printf("The expression is empty");
return;
}
while(t!=NULL)
{
printf("%dX^%d ",t->coff,t->exp);
t=t->link;

if(t!=NULL)
if(t->coff>0)
printf("+ ");
}
printf("\n");
}
void add(node *p, node *q, node **r)
{
node *i=p,*j=q,*k=NULL,*temp;
while(i!=NULL&&j!=NULL)
{
temp=(node *) malloc(sizeof(node));
if(i->exp==j->exp)
{
temp->coff=i->coff+j->coff;
temp->exp=i->exp;
i=i->link;
j=j->link;
}
else if(i->exp>j->exp)
{
temp->coff=i->coff;
temp->exp=i->exp;
i=i->link;
}
else
{
temp->coff=j->coff;
temp->exp=j->exp;
j=j->link;
}
if(*r==NULL)
{
*r=k=temp;
}
else
{
k->link=temp;
k=temp;
}
}
if(i==NULL)
while(j!=NULL)
{

temp=(node *) malloc(sizeof(node));
temp->coff=j->coff;
temp->exp=j->exp;
k->link=temp;
k=temp;
j=j->link;
}
else
while(i!=NULL)
{
temp=(node *) malloc(sizeof(node));
temp->coff=i->coff;
temp->exp=i->exp;
k->link=temp;
k=temp;
i=i->link;
}
k->link=NULL;
}
void main()
{
node *f=NULL, *s=NULL,*r=NULL;
clrscr();
printf("Enter the First Polynomial Equation\n");
create(&f);
printf("Enter the Second Polynomial Equation\n");
create(&s);
printf(" The Given First Polynomial Equation is ..\n");
disp(f);
printf(" The Given Second Polynomial Equation is ..\n");
disp(s);
add(f,s,&r);
printf(" The Resultant Polynomial Equation is ..\n");
disp(r);
}