#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 100
int top=-1;
char opr[size];
char opn[size];
void push(char item)
{
	top++;
	opr[top]=item;
	
}
char pop()
{
	char item=opr[top];
	top--;
	return item;
}
int pre(char item)
{if(item=='(')
return 1;
if(item=='^')
return 4;   
if(item=='*'||item=='/')
    return 3;
	if(item=='+'||item=='-')
	return 2;
}
void main()
{
	char infix[size];
	int i=0,j=-1;
	int o1,o2;
	char a,b;
	gets(infix);
	while(infix[i]!='\0')
	{ a=infix[i];
	 if(a=='(')
	 {
	 	push(a);
	 	
	 }
	 
	 else if((a>='A'&&a<'Z')||(a>='a'&&a<'z'))
	 {j++;
	 opn[j]=a;
	 }
	else if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
	{   b=pop();
	    o1=pre(b);
	    o2=pre(a);
	    
		if(o2>o1)
		{push(b);
		push(a);
		
		}
		else
		{j++;
		opn[j]=b;
		b=pop();
		while(pre(b)>=pre(a))
		{
		j++;
		opn[j]=b;
		b=pop();
		
		}
		push(b);
		push(a);
		}
		
	}
	else if(a==')')
	{b=pop();
     do
	 {
	 j++;
     opn[j]=b;
     b=pop();
 }while(b!='(');
   }
		i++;
	}
	while(top!=-1)
	{b=pop();
	j++;
	opn[j]=b;
	}
	puts(opn);
}
