#include<stdio.h>
#include<conio.h>
int fact(int n)
{  
	if(n==0||n==1)
	return 1;
	else
	{
		n=n*fact(n-1);
	}
	return n;
}
float* difftable(float y[],int n)
{   float bdiff[n];
    int i,j;
    bdiff[0]=y[n-1];
	for(j=0;j<n-1;j++)
	{

	for(i=n-1;i>j;i--)
	{   
	    y[i]=y[i]-y[i-1];
	}
	bdiff[j+1]=y[n-1];
	for(i=j+1;i<n;i++)
	printf("%f ",y[i]);
	printf("\n");
}

return bdiff;
}
float pcount(float p,int count)
{int i;
if(count==0)
return 1;
if(count==1)
return p;
float sub=p;
for(i=1;i<count;i++)
 sub=sub*(p-i);
 return sub;
}
void main()
{int n,i,j;
float q ,value=0;
float p,h;
float *temp;
 printf("Enter no of values : ");
 scanf("%d",&n);
 float x[n],y[n],d[n];
 printf("Enter value for x :\n");
 for(i=0;i<n;i++)
 scanf("%f",&x[i]);
 printf("Enter value for y :\n");
 for(i=0;i<n;i++)
 scanf("%f",&y[i]);
 printf("backward difference table is : \n");
 temp=difftable(y,n);
 for(i=0;i<n;i++)
{d[i]=*temp;
temp++;
}
 printf("Enter value of x to calculate solution : ");
 scanf("%f",&q);
 h=x[1]-x[0];
 p=(q-x[n-1])/h;
 
 for(i=0;i<n;i++)
{
	value=value+(d[i]*pcount(p,i))/fact(i);
}
	printf(" solution for  %f is   %f ",q,value);
}
