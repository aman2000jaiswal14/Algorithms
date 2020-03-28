#include<stdio.h>
#include<conio.h>
int count=0;
int toh(int n , char start,char aux,char end)
{
	if(n==1)
	{
		printf("%c     to     %c\n",start,end);
		 count++;
		return 1;
	}
     toh(n-1,start,end,aux);
     printf("%c     to     %c\n",start,end);
     toh(n-1,aux,start,end);
      count++;
	 return 2;
     
}
int main()
{int n;
printf("ENTER NUMBER OF DISK : ");
scanf("%d",&n);
toh(n,'A','B','C');
printf("\ncount = %d\n",count);
getch();

	return 0;
}
