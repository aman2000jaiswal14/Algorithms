#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BinarySearchTree{
	struct BinarySearchTree *left,*right;
	int data;
};
struct BinarySearchTree *r=NULL;
struct BinarySearchTree* CreateNode()
{
	struct BinarySearchTree* temp=(struct BinarySearchTree *)malloc(sizeof(struct BinarySearchTree));
	if(temp==NULL)
	printf("NULL M");
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(struct BinarySearchTree* b,int data)
{    
    struct BinarySearchTree* temp2;
	struct BinarySearchTree* temp=CreateNode();
	temp->data=data;
//	
	if(b==NULL)
	{
	b=temp;
}
	else 
	{
	   temp2=b;
		while(1)
		{   
			if(temp2->data>data)
			temp2=temp2->left;
			else if(temp->data<data)
			temp2=temp2->right;
			if(temp2==NULL)
			{
				temp2=temp;
			}
			
		}
}

}
struct BinarySearchTree* find(struct BinarySearchTree* b,int data)
{
	struct BinarySearchTree* temp;
	temp=b;
	
	while(1)
	{
		if(temp==NULL)
		{printf("\nNo data found\n");
		return NULL;
		}
		else if(temp->data==data)
		return temp;
		else if(temp->data>data)
		temp=temp->left;
		else if(temp->data<data)
		temp=temp->right;
	}
	
}

void inorder(struct BinarySearchTree *b)
{
	if(b==NULL)
	return;
	else
	{
		printf(" %d ",b->data);
		inorder(b->left);
		inorder(b->right);
	}
}


void main()
{
	struct BinarySearchTree *root1=NULL,*temp=NULL;
	int ch,data;
	while(1)
	{   printf("\nEnter choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:
	    		printf("\nEnter data : ");
	    		scanf("%d",&data);
	    		insert(root1,data);
	    		break;
	        case 2:
	        	printf("\Enter data : ");
	        	scanf("%d",&data);
	        	temp=find(root1,data);
	        	if(temp!=NULL)
	        	printf("\nData Found\n");
	        	break;
	        case 3: 
	            if(root1==NULL)
	            printf("ghbgfxn0");
			    inorder(root1);
			    getch();
				break;	
			     		
		}
		
	}
	
	
}
