//Drrrrrrrr

#include<stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list * next;
}list;

list * input_list(list *head, int n)
{
	int i;
	list *p,*prev;

	head=NULL;

	printf("Enter the value of %d integers to fill the list :\n");

	for(i=0;i<n;i++)
	{
		p=(list *)malloc(sizeof(list));
		scanf("%d",&p->data);

		p->next=NULL;

		if(head==NULL) head=p;
		else prev->next=p;

		prev=p;
	}

	return head;
}

void print_list(list *head)
{
	list * p;

	p=head;

	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}

}

void rearrange(int *a,int *b)
{
	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void list_rearrange(list* head)
{
    list* temp = head;
 
    while (temp != NULL && temp->next != NULL)
     {
        rearrange(&temp->data, &temp->next->data);
 
        temp = temp->next->next;
    }
}
 

int main()
{
	int i;
	int n;

	printf("Enter the number of elements that are going to be in the list: ");
	scanf("%d",&n);

	list *head;

	while(1)
	{
		if(n>=1) break;
		else
		{
			printf("Please enter a value of n which is greater than or equal to 1 :");
			scanf("%d",&n);
		} 

	}

	head=input_list(head,n);

	list_rearrange(head);

	printf("The Rearranged list of elements is : ");

	print_list(head);


	return 0;

}

