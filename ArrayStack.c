#include<stdio.h>
#include<conio.h>
struct ArrayStack{
	int top;
	unsigned int capacity;
	int *array;
};
struct ArrayStack* CreateArrayStack(int cap)
{
		struct ArrayStack *stack;
		stack=(struct ArrayStack*)malloc(sizeof(struct ArrayStack));
		stack->capacity=cap;
		stack->top=-1;
		stack->array=(int *)malloc(sizeof(int)*cap);
		return stack;
		}
int isfull(struct ArrayStack* stack){
	if(stack->top==stack->capacity-1)
	return 1;
	else
	return 0;
}		
int isempty(struct ArrayStack* stack){
	if(stack->top==-1)
	return 1;
	else
	return 0;
}
void push(struct ArrayStack* stack,int item){
		stack->top=stack->top+1;
		stack->array[stack->top]=item;
}
int pop(struct ArrayStack* stack){
    	int item;
    	item=stack->array[stack->top];
    	stack->top=stack->top-1;
        return item;
    }
int main(){
	int capacity,choice,item;
	struct ArrayStack* stack;
	printf("ENTER CAPACITY OF STACK   ");
	scanf("%d",&capacity);
	stack=CreateArrayStack(capacity);
	while(1){
		printf("\n1 -> PUSH\n2 -> POP\n3 -> EXIT\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				if(!isfull(stack)){
				printf("\nENTER ITEM   ");
				scanf("%d",&item);
				push(stack,item);}
				else
				printf("\nSTACK IS FULL");
				break;
			case 2:
				if(!isempty(stack)){
			    item=pop(stack);
				printf("\nPOPED ITEM IS %d",item);}
				else
				printf("\nSTACK IS EMPTY");
				break;
			case 3:
			    exit(3);
				break;
			default:
				printf("\nWRONG INPUT TRY AGAIN");
					
		}
	}
	return 0;
	}
		
