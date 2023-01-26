/Binary search Tree  
#include<stdio.h>  
#include<stdlib.h>  
int ch;  
typedef struct slist  
{  
 int data;  
 struct slist *left,*right;  
}node;  
node *root=NULL;  
void insert();  
void del();  
void find(node *r,int item, node **l,node **p);  void preorder(node *ptr);  
void inorder(node *ptr);  
void postorder(node *ptr);  
void casea(node **loc,node **ptr);  void caseb(node **loc,node **ptr);  void preorder(node *ptr)  
{  
 if(ptr==NULL)  
 {  
 printf("Tree is empty");   return;  
 }  
 printf("%d ",ptr->data);  
 if(ptr->left!=NULL)  
 preorder(ptr->left);   if(ptr->right!=NULL)  
 preorder(ptr->right);  }  
void inorder(node *ptr)  
{  
 if(ptr==NULL)  
 {  
 printf("Tree is empty");   return;  
 }  
 if(ptr->left!=NULL)  
 inorder(ptr->left);  
 printf("%d ",ptr->data);  
 if(ptr->right!=NULL)  
 inorder(ptr->right);  }  
void postorder(node *ptr) 
{  
 if(ptr==NULL)  
 {  
 printf("Tree is empty");   return;  
 }  
 if(ptr->left!=NULL)  
 postorder(ptr->left);  
 if(ptr->right!=NULL)  
 postorder(ptr->right);  
 printf("%d ",ptr->data);  
}  
void insert()  
{  
 node *fresh,*loc,*par;  
 int item;  
 printf("Enter item to be inserted:");   scanf("%d",&item);  
 find(root,item,&loc,&par);  
 if(loc!=NULL)  
 {  
 printf("Item already exists");   return;  
 }  
 fresh=(node *) malloc(sizeof(node));   fresh->data=item;  
 fresh->left=fresh->right=NULL;  
 if(par==NULL)  
 {  
 root=fresh;  
 return;  
 }  
 if(item<par->data)  
 par->left=fresh;  
 else  
 par->right=fresh;  
}  
void find(node *ptr,int item,node **loc,node **par) { node *save;  
 if(ptr==NULL)  
 {  
 *loc=*par=NULL;  
 return;  
 }  
 if(item==ptr->data) 
 {  
 *loc=ptr;  
 *par=NULL;  
 return;  
 }  
 if(item<ptr->data)  
 {  
 save=ptr;  
 ptr=ptr->left;   }  
 else  
 {  
 save=ptr;  
 ptr=ptr->right;   }  
 while(ptr!=NULL)  
 {  
 if(item==ptr->data)   {  
 *loc=ptr;   *par=save;   return;   }  
 if(item<ptr->data)   {  
 save=ptr;   ptr=ptr->left;   }  
 else  
 {  
 save=ptr;   ptr=ptr->right;   }  
 }  
 *loc=NULL;  
 *par=save;  
}  
void del()  
{  
 node *loc=NULL,*par=NULL;   int item;  
 if(root==NULL)  
 {  
 printf("Underflow");   return; 
 }  
 printf("Enter the item to be deleted");   scanf("%d",&item);  
 find(root,item,&loc,&par);  
 if(loc==NULL)  
 {  
 printf("Item not found");   return;  
 }  
 if(loc->left!=NULL&&loc->right!=NULL)   caseb(&loc,&par);  
 else  
 casea(&loc,&par);  
 free(loc);  
}  
void casea(node **loc,node **par)  
{  
 node *child;  
 if((*loc)->left==NULL&&(*loc)->right==NULL)   child=NULL;  
 else if((*loc)->left!=NULL)  
 child=(*loc)->left;  
 else  
 child=(*loc)->right;  
 if(*par!=NULL)  
 {  
 if((*loc)==(*par)->left)  
 (*par)->left=child;   else  
 (*par)->right=child;   }  
 else  
 root=child;  
}  
void caseb(node **loc,node **par)  
{  
 node *ptr,*save,*suc,*psuc;  
 ptr=(*loc)->right;  
 save=*loc;  
 while(ptr->left!=NULL)  
 {  
 save=ptr;  
 ptr=ptr->left;  
 }  
 suc=ptr; 
 psuc=save;  
 casea(&suc,&psuc);  
 if(*par!=NULL)  
 {  
 if((*loc)==(*par)->left)  
 (*par)->left=suc;  
 else  
 (*par)->right=suc;  
 }  
 else  
 root=suc;  
 suc->left=(*loc)->left;  
 suc->right=(*loc)->right;  
}  
void menu()  
{  
 printf("\n1.Insert 2.Delete 3.Preorder 4.Inorder 5.Postorder 6.Exit\n");   printf("Enter your choice:");  
 scanf("%d",&ch);  
}  
void main()  
{  
 clrscr();  
 menu();  
 while(ch<6)  
 {  
 switch(ch)  
 {  
 case 1:insert();break;  
 case 2:del();break;  
 case 3:preorder(root);break;  
 case 4:inorder(root);break;  
 case 5:postorder(root);break;  
 }  
 menu();  
 }  
} 
