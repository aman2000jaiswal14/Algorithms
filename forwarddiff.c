#include<stdio.h>
#include<conio.h>
int fact(int n)
{   int i;
    int fact=1; 
    if(n==0)
    return 1;
	for(i=1;i<=n;i++)
	fact=fact*i;
	return fact;
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
float *Fdiff(float a[],int n)
{   float ret[n];
    ret[0]=a[0];
	int i,j;
	for(i=0;i<n-1;i++)
	{for(j=0;j<n-i-1;j++)
	 {
	  
	  a[j]=a[j+1]-a[j];
	  
	  
	 }
	 
	 ret[i+1]=a[0];
	}
	return ret;
	}



void main()
{int i;
float p;
float x;
int x0;
int n;
float h;
float value=0;
printf("Enter the no. of values : ");
scanf("%d",&n);
float a[n];
float b[n];
float d[n];
for(i=0;i<n;i++)
{printf("x : ");
scanf("%f",&a[i]);
printf("y : ");
scanf("%f",&b[i]);
}
printf("Enter value of x where to find solution : ");
scanf("%f",&x);
h=a[1]-a[0];
p=(x-a[0])/h;

float *temp;
temp=Fdiff(b,6);
for(i=0;i<n;i++)
{d[i]=*temp;
temp++;
}
for(i=0;i<n;i++)
printf("%d forward difference is  %f\n",i,d[i]);

temp=NULL;
free(temp);
for(i=0;i<n;i++)
{
	value=value+(d[i]*pcount(p,i))/fact(i);
}

printf(" solution for  %f is   %f ",x,value);
	
}
