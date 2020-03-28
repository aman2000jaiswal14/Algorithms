#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Arrayqueue{
	int *arr;
	int rear;
	int front;
	int cap;
};
struct Arrayqueue* CreateArrayQueue(int capacity)
{struct Arrayqueue* p=(struct Arrayqueue * )malloc(sizeof(struct Arrayqueue));
if(p!=NULL)
{p->arr=(int *)malloc(sizeof(int)*capacity);
if(p->arr!=NULL)
{
p->cap=capacity;
p->front=-1;
p->rear=-1;
}
}
	
}
int isempty(struct Arrayqueue* p)
{
	if(p->front==-1)
	return 1;
	else
	return 0;
}
int isfull(struct Arrayqueue* p)
{if((p->rear+1)%p->cap==p->front)
	return 1;
	 else
	return 0;
}
void insert(struct Arrayqueue* p)
{
     if(!isfull(p))
     {   p->rear=(p->rear+1)%p->cap;
	     if(p->front==-1)
         {p->front=0;
		 } 
		 printf("\nEnter Data: ");
		 scanf("%d",&p->arr[p->rear]);
		 
	 }
	 else{
	 	printf("\noverflow\n");
	 }
}
void delete(struct Arrayqueue* p)
{   int item;
	if(!isempty(p))
	{item = p->arr[p->front];
	if(p->front==p->rear)
	   { p->rear=-1;
		 p->front=-1;
	}
	else    
	p->front=(p->front+1)%p->cap;
	
	printf("\n poped item : %d \n",item);
	}
	else
	printf("underflow");
}
void Queuesize(struct Arrayqueue* p)
{
	int size;
	if(p->front==-1)
	size=0;
	else if(p->rear>=p->front)
	    size=p->rear-p->front+1;
    else
        size=p->cap-p->front+p->rear+1;
    printf("\nSize of queue : %d \n",size);
}
void main()
{   int cap,c;
	struct Arrayqueue* queue;
	printf("ENTER CAPACITY OF ARRAYQUEUE : ");
	scanf("%d",&cap);
	queue=CreateArrayQueue(cap);
	while(1)
	{printf("\n1 INSERT\n2 DELETE\n3 SIZE\n4 EXIT\n");
	 scanf("%d",&c);
	 switch(c)
	 { 
	    case 1:
	   	    insert(queue);
	   	    break;
	    case 2:
	    	delete(queue);
	    	break;
	    case 3:
		    Queuesize(queue);
			break;	
	    case 4:
	    	exit(0);
	    default:
		    printf("\nWrong input\n");	
	 }
		
	}
}
