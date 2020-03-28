#include<stdio.h>
#include<conio.h>
#include<math.h>
#define eps 0.0001

struct poly{
	float coeff;
	int power;
	struct poly* next; 
};
struct poly* start=NULL;
struct poly* createpoly()
{
	struct poly* p=(struct poly*)malloc(sizeof(struct poly));
	return p;
}
void insert()
{
  	struct poly* p,*q;
	p=createpoly();
	printf("ENTER COEFFICENT AND EXPONENT OF X  :  ");
	scanf("%f%d",&p->coeff,&p->power);
	p->next=NULL;
	if(start==NULL)
	start=p;
	else
	{q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
}
}
void display()
{
	struct poly* p;
	if(start==NULL)
	{printf("EMPTY");
	}
	else
	{p=start;
	printf("F(X) = ");
	while(p!=NULL)
	{printf("+ %fX(%d) ",p->coeff,p->power);
	 p=p->next;
	}
	}
	
}
float func(float x)
{   struct poly*p;
	float sum=0;
	if(start==NULL)
	{
	return 0;
	}
	
	else
	{
	p=start;
	while(p!=NULL)
	{sum = sum + (p->coeff)*pow(x,p->power);
	 p=p->next;
	}
    return sum;	
    }
}
void del()
{   struct poly* p;
	if(start==NULL)
	{printf("empty\n");
	}
	else if(start->next==NULL)
	{start=NULL;
	}
	else
	{p=start;
		while((p->next)->next!=NULL)
		p=p->next;
		p->next=NULL;
		
	}
}

float pos(float x,float y)
{if(x>y)
 return x-y;
 else 
 return y-x;
}


int main()
{int n,j,k=0,i,temp=0,value;
float a,b,c=0,c1=100,d,r0,r1,r2;
	while(1)
	{printf("\n 1 insert term \n 2 remove term \n 3 display\n 4 bisection\n 5 exit\n");
	 scanf("%d",&n);
	 switch(n){
	 	case 1:
	 		insert();
	 		break;
	    case 2:
		    del();
		    break;
		case 3:
		    display();
		    break;
		case 4:
			if(start==NULL)
			{printf("Empty");
			 return 0;
			}
			 a=0;
			 b=0;
			 r0=func(0);
			 if(r0==0){
			 printf(" 0 is the root");
			 return 0;
			 }
 for(i=1;i<1000;i++)
 {if(func(i)==0)
  {printf("%d is the absolute root ",i);
  return 9;
  }
 if(r0*func(i)<0)
    {r1=i;
    r2=i-1;
    temp=1;
	break;}
 }
 if(temp==0)
 {for(j=-1;j>-1000;j--)
 {
 if(func(j)==0)
  {printf("%d is the absolute root ",j);
  return 8;
  }
  if(r0*func(j)<0)
  {r1=j;
   r2=j+1;
   temp=2;
   break;
  }}
 }
 if(temp==0)
  {printf("no root");
  return 5;
  }
  if(func(r1)<0)
  {a=r1;
  b=r2;
  }
  else
  {a=r2;
  b=r1;
  }
  printf("a = %f   b = %f  ",a,b);
 if(func(a)*func(b)>=0)
  return 2;
do{k++;
 c1=c;
	c=(a+b)/2;
	printf("\nIteration %d : c = %f  f(c) = %f\n",k,c,func(c));
	if(func(c)<0)
	a=c;
	else if(func(c)>0)
	b=c;
	d=pos(c1,c);
}while(d>=eps);
if(func(c1)>func(c))
printf("%f is root",c);
else
printf("%f is root ",c1); 
getch();
break;
			
		case 5:
		return 5;        
        default:
		    printf("wrong input");			    				
	 }
		
	}
	return 0;}
