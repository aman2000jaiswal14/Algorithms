/* bubble sort*/
#include <stdio.h>
#include <conio.h>
int main()
{int n,temp;
int i,j;
int *arr;
scanf("%d",&n);
arr=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n-1;i++)
{for(j=0;j<n-i-1;j++){
	if(arr[j]>arr[j+1])
	{temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
	}
	
}
  }  
for(i=0;i<n;i++)
printf(" %d ",arr[i]);
getch();  
	return 0;
}
