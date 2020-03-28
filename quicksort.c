#include<stdio.h>
#include<conio.h>
void quick(int a[],int beg,int end,int *loc)
{  
	int left,right,temp;
	left=beg;
	right=end;
	*loc=beg;

while(1)
{
		while(a[*loc]<=a[right]&& (*loc!=right))
	right--;	
	if(*loc==right)
	return;
	if(a[*loc]>a[right]){
	temp=a[*loc];
	a[*loc]=a[right];
	a[right]=temp;
	*loc=right;
}
	while(a[*loc]>=a[left] && (*loc!=left))
	{left++;
	}
	if(*loc==left)
	return;
	if(a[*loc]<a[left]){
	
	temp=a[*loc];
	a[*loc]=a[left];
	a[left]=temp;
	*loc=left;
}
}

}
void quicksort(int a[],int beg,int end){
	if(beg==end)
	return;
	int loc;
	quick(a,beg,end,&loc);
	if(loc-1>beg)
	quicksort(a,beg,loc-1);
	if(loc+1<end)
	quicksort(a,loc+1,end);
	
}
void quicksort_stack(int a[],int N){
	int loc,beg=0,end=N-1,top=-1;
	int l[10],u[10];
	if(N>1)
	{top++;
	l[top]=0;
	u[top]=N-1;
	}
	else 
	return;
	while(top!=-1)
	{beg=l[top];
	 end=u[top];
	 top--;
	 quick(a,beg,end,&loc);
	 if(beg<loc-1)
	{
	  top++;
	 l[top]=beg;
	 u[top]=loc-1;
}
	 if(loc+1<end)
	 {
	 top++;
	 l[top]=loc+1;
	 u[top]=end;
}
	 
		
	}
}

int main()
{   
	int i,a[10]={21,43,32,200,65,44,76,100,98,87};
    quicksort(a,0,9);
    printf("without using stack:\n");
	for(i=0;i<10;i++)
	printf(" %d ",a[i]);
	
	int b[10]={21,43,32,200,65,44,76,100,98,87};
	quicksort_stack(b,10);
	printf("\nusing stack:\n");
	for(i=0;i<10;i++)
	printf(" %d ",b[i]);
	return 0;
}
