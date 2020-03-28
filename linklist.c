#include<stdio.h>
#include<conio.h>
struct node{
	int data;
	struct node * next;
};
struct node* Head=NULL;
struct node* Create_linklist()
{
	struct node* t=(struct node* )malloc(sizeof(struct node));
    return t;	
}
void Insert_first()
{
	struct node* p;
	struct node* q;
	q=Create_linklist();
	q->next=NULL;
	printf("ENTER DATA : ");
	scanf("%d",&q->data);
	if(Head==NULL)
	{Head=q;
	}
	else{
		p=Head;
		Head=q;
		Head->next=p;
	}
}
//int Insert_between()
//{   int n,i=0;
//	struct node *p,*r;
//	struct node *q=Create_linklist();
//	q->next=NULL;
//	printf("ENTER THE POSITION : ");
//	scanf("%d",&n);
//	if(Head==NULL)
//	{printf("LIST IS EMPTY");
//	return 2;
//	}
//	p=Head;
//	while(p->next!=NULL)
//	{i++;
//	 if(i==n-1)
//	 {printf("ENTER DATA : ");
//	  scanf("%d",&q->data);
//	  r=p;
//	  p->next=q;
//	  q->next=r;
//	  free(p);
//	  free(r);
//	  return 0;
//	 }
//	}
//	printf("Position not found");
//	return 1;
//	
//}
void delete_between()
{
	struct node *p;
	struct node *q;
	struct node *r;
	int n;
	if(Head==NULL)
	{printf("empty\n");
	}
	else{
	
	printf("ENTER DATA TO DELETE : ");
	scanf("%d",&n);
	p=Head;
	while(p->next!=NULL)
	{if((p->next)->data==n)
	 {if((p->next)->next!=NULL){
	 q=(p->next)->next;
	  p->next=q;}
	  else
	  {p->next=NULL;
	  }
	  return 4;
	  }
	 
     p=p->next;
     
	}
	printf("DATA NOT FOUND");
	}
}
void Insert_data_last()
{
	struct node * t;
	struct node * n=Create_linklist();
	printf("ENTER DATA : ");
	scanf("%d",&n->data);
	n->next=NULL;
	if(Head==NULL)
	{Head=n;
	}
	else
	{
	t=Head;
	while(t->next!=NULL)
	 t=t->next;
	 t->next=n;
	}
	
}
void Print_linklist()
{   struct node* t;
	if(Head==NULL)
	   printf("list is empty\n");
	else
	{t=Head;
	 while(t!=NULL)
	 {
	 	printf(" %d ",t->data);
	 	t=t->next;
	 	
	 }
	   }   
}
void Delete_first_data()
{
	struct node * t;
	if(Head==NULL)
	 printf("list is empty\n");
	else{
		t=Head;
		Head=Head->next;
//		free(t);
		} 
}
int main()
{
	int n;
	while(1)
	{
        printf("\n1 Insert data at last\n2 delete first data\n3 printlinklist\n4 insert at first\n5 exit ");
		printf("\nEnter choice :  ");
		scanf("%d",&n);
		switch(n){
			case 1:
				Insert_data_last();
				break;
		    case 2:
			    Delete_first_data();
			    break;
			case 3:
			    Print_linklist();
			    break;
			case 4:
				Insert_first();
				break;
			case 6:
			    delete_between(); 
			    break;
		    case 5:
		    	return (1);
			default:
			   return (2);					
		}
	}
	return 0;
}
