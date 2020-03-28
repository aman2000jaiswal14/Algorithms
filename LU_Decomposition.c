#include<stdio.h>
#include<math.h>
#include<conio.h>
#define MAX 100
float linear(float v[],int t,float d)
{float temp;
if(v[t]!=2)
temp=1;
else
temp=v[t-1];
t--;
while(t>0)
{
	t=t-2;
	d=d-(v[t]*v[t+1]);
}

return d/temp;
 
}

int main()
{   
float d,vale,value_stk[MAX];
 int top=-1;
 int n,i,j,k,l,m,o;
 float val=0;
 printf("Enter no. of variables : ");
 scanf("%d",&n);
 float a[n][n],b[n],c[n][n],lwr[n][n],upr[n][n];
 float x[n],y[n];
 float s_lwr[n][n],s_upr[n][n];
 
 
 for(i=0;i<n;i++){ 
 printf("Enter %d coefficent of %d equation with 1 constant value  : ",n,i+1);
 for(j=0;j<n;j++)
 scanf("%f",&a[i][j]);
 scanf("%f",&b[i]);
}
//lwr and upr-------- 
for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
   {
   if(i>=j)
   {s_lwr[i][j]=2;
   lwr[i][j]=2;
   }
   else
   {
   	s_lwr[i][j]=0;
   lwr[i][j]=0;  
   }
}
 }
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
   {
   if(i<j)
   {upr[i][j]=2;
   s_upr[i][j]=2;
   }
   else if(i==j)
   {
   s_upr[i][j]=1;
   upr[i][j]=1;
   }
   else{
   s_upr[i][j]=0;  
   upr[i][j]=0;  
   }
}
}


	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{  
			
				for(l=0;l<n;l++)
				{

                    if(lwr[i][l]*upr[l][j]!=0)
					{
						top++;
						if(l==0&&s_lwr[i][l]==2)
						value_stk[top]=2;
						else
						value_stk[top]=lwr[i][l];
						
						top++;
						if(l==0&&s_upr[l][j]==2)
						value_stk[top]=2;
						else
						value_stk[top]=upr[l][j];
						
					 } 
	         
					
			}
			  
		    val = linear(value_stk,top,a[i][j]);
			if(s_lwr[i][j]==2)
			    {
			        lwr[i][j]=val;
		            s_lwr[i][j]=-1;
		        }
			else
		        {
			    	upr[i][j]=val;
				    s_upr[i][j]=-1;
				
                }  
            top=-1;

		}
	}
	
	
	//---lwr upr print-------
	printf("\nlower triangular matrix is : \n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{printf("%f   ",lwr[i][j]);
		}
		printf("\n");
	}
	printf("\n uper triangular matrix is : \n");
 	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{printf("%f   ",upr[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{ top++;
		  value_stk[top]=lwr[i][j];
		  top++;
		  if(i==j)
		  value_stk[top]=2;
		  else
		  value_stk[top]=y[j];
	
		}
			val=linear(value_stk,top,b[i]);
			y[i]=val;
			top=-1;
	}
	
	for(i=n;i>=0;i--)
	{
	for(j=n-i;j>=i;j--)
    {
		top++;
		if(j==i){	
		value_stk[top]=1;
		top++;
		value_stk[top]=2;
	}
	else
	{
	    value_stk[top]=upr[i][j];
	    top++;
	    value_stk[top]=x[j];
    }
    }

	val=linear(value_stk,top,y[i]);
	x[i]=val;
	top=-1;
	}
	printf("\nsolution of equations are  \n");
	for(i=0;i<n;i++)
	printf("%f  ",x[i]);
	return 0;
}
