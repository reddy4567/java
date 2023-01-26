//Evaluation of Postfix expression  
#include<stdio.h>  
#include<math.h>  
int top=-1;  
float stk[50];  
void push(float p)  
{  
 stk[++top]=p;  
}  
float pop()  
{  
 return stk[top--];  
}  
void main()  
{  
 char p[50];  
 float data[50],a,b;  
 int i=0;  
 clrscr();  
 printf("Enter Postfix Expression with out any blank spaces:");   scanf("%s",p);  
 while(p[i]!='\0')  
 {  
 if(isalpha(p[i]))  
 {  
 printf("Enter values of %c:",p[i]);   scanf("%f",&data[i]);  
 }  
 i++;  
 }  
 p[i]=')';  
 i=0;  
 while(p[i]!=')')  
 {  
 switch(p[i])  
 {  
 case'+': a=pop();b=pop();push(b+a);break;   case'-': a=pop();b=pop();push(b-a);break;   case'*': a=pop();b=pop();push(b*a);break;   case'/': a=pop();b=pop();push(b/a);break;  
 case'^': a=pop();b=pop();push(pow(b,a));break;   default: push(data[i]);  
 } 
 i++;  
 }  
 p[i]='\0';  
 printf("The given postfix expression is:");  
 for(i=0;p[i];i++)  
 {  
 if(isalpha(p[i]))  
 printf("%f ",data[i]);  
 else  
 printf("%c ",p[i]);  
 }  
 printf("\n The result of evaluated postfix expression is:%f",pop());  } 
