#include <stdio.h>
#include<stdlib.h>

 struct node
{
	int data;
	struct node* next;
};

int main()
{
	char a[100],b[100];
	int i,temp,max_length;

	printf("Enter the first integer : ");
	scanf("%s",a);
	printf("Enter the second integer: ");
	scanf("%s",b);

	struct node *head_a=NULL,*head_b=NULL,*p,*prev;

	for(i=0;a[i]!='\0';i++,max_length++)
	{
		p=(struct node*)malloc(sizeof(struct node));

		p->data=a[i]-'0';

		if(head_a==NULL)
		{
			head_a=p;
		}
		else
		{
			prev->next=p;
		}
		prev=p;

	}
	p->next=NULL;

	for(i=0;b[i]!='\0';i++)
	{
		p=(struct node*)malloc(sizeof(struct node));

		p->data=b[i]-'0';

		if(head_b==NULL)
		{
			head_b=p;
		}
		else
		{
			prev->next=p;
		}
		prev=p;

	}

	if(i>max_length)
	{
		max_length=i;

		// Making sure that head_a has the highest length number

		p=head_a;
		head_a=head_b;
		head_b=p;
	}
	p->next=NULL;

	for(i=0;head_b!=NULL;i++)
	{
		if(head_a->data+head_b->data+temp>9)
		{
			printf("%d",head_a->data+head_b->data+temp-10);
			temp=1;
		}
		else
		{
			printf("%d",head_a->data+head_b->data+temp);
			temp=0;
		}
		head_a=head_a->next;
		head_b=head_b->next;

	}
	printf("\n");

	while(head_a!=NULL)
	{
		while(head_a->data==9)
		{
			printf("0");
			head_a=head_a->next;
		}

		printf("%d",head_a->data);
		head_a=head_a->next;
	}

	// p=head_a;

	// while(p!=NULL)
	// {
	// 	printf("%d",p->data);
	// 	p=p->next;
	// }

	return 0;

}