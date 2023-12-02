#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node* next;
};
int main()
{
	char a[100],b[100];  // Let a and b be the two input strings and let us assume their maximum size of the string to be 100
	int lenght_a,lenght_b;
	int i;
	
	printf("Enter the first number: ");
	scanf("%s",a);
	printf("Enter the second number: ");
	scanf("%s",b);

	lenght_a=strlen(a);
	lenght_b=strlen(b);

	struct node *head_a,p=NULL;
	head_a=(struct node*)malloc(sizeof(struct node));
	head_a->next=NULL;

	struct node *head_b=NULL;
	struct node *temp;

	for(i=0;i<lenght_a;i++)
	{
		if(head_a->next==NULL)
		{
			head_a->data=a[i];
			head_a->next=p;
		else             
		{
			p=(struct node*)malloc(sizeof(struct node));
			p->data=a[i];
			p=p->next;
		}

		
	}

	temp=head_a;

	while(temp->next!=NULL)
	{
		printf("%c",temp->data);
		temp=temp->next;
	}







}