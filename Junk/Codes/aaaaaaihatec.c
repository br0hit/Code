#include<stdio.h>

typedef struct
{
	char name[20];
	char address[20];
	int mobile_number;
	int customer_number;
	
}cust;

typedef struct
{
	int no_items;
	int code[10];
	int amount[10];
	char date[7];

	int customer_number;

}sales;

void Register_customer(cust customer,int customer_index)
{
	printf("Enter the name of the new customer :");
	scanf("%s",customer.name);
	printf("Enter the address of the customer : ");
	scanf("%s",customer.address);
	printf("Enter the mobile number of the customer: ");
	scanf("%d",&customer.mobile_number);

	customer.customer_number=customer_index;

	printf("The details of the new customer entered by the user are : \n");
	printf("Name : %s\nAddress : %s\nMobile Number : %d\nCustomer Number : %d",customer.name,customer.address,customer.mobile_number,customer.customer_number);


}

void List_customer(cust customer[],int customer_index)
{
	int i;

	printf("The list of detailes of all the customers are : \n");

	for(i=0;i<customer_index;i++)
	{
		printf("Name : %s\nAddress : %s\nMobile Number : %d\nCustomer Number : %d\n\n",customer[i].name,customer[i].address,customer[i].mobile_number,customer[i].customer_number);
	}

}

void Modify_customer(cust customer[], int customer_index)
{
	int Modify_index;

	printf("Enter the CN of the customer who's details are to be changed : ");
			scanf("%d",Modify_index);

	if(Modify_index>customer_index) printf("The customer with the entered CN does not exist ");
	else
	{
		printf("\nThe Detalis of the customer with CN %d are \n",Modify_index);
		printf("Name : %s\nAddress : %s\nMobile Number : %d\nCustomer Number : %d\n\n",customer[Modify_index].name,customer[Modify_index].address,customer[Modify_index].mobile_number,customer[Modify_index].customer_number);

		printf("Enter the new details : \n");
		Register_customer(customer[Modify_index],Modify_index);

	}
}

void Sale(sales sale[],int sale_index)
{
	int input;
	int i;

	printf(" Enter he customer index of the person making the sale :");
	scanf("%d",&input);

	printf("Enter the number of items to be purchased : ");
	scanf("%d",sale[sale_index].no_items);

	for(i=0;i<sale[sale_index].no_items;i++)
	{
		printf("Enter the item code : ");
		scanf("%d",&sale[sale_index].code[i]);
		printf("Enter the amount of purchase for the particualar code :");
		scanf("%d",&sale[sale_index].amount[i]);
	}

	printf("Enter the date of purchase in the format of dd-mm-yy :");
	scanf("%s",sale[sale_index].date);

	sale[sale_index].customer_number=input;

}

void Display_sale(sales sale[],cust customer[],int sale_index)
{
	int input;
	int i;

	printf("Enter the customer number :");
	scanf("%d",input);

	printf("The details of the customer are : \n");
	printf("Name : %s\nAddress : %s\nMobile Number : %d\nCustomer Number : %d\n\n",customer[input].name,customer[input].address,customer[input].mobile_number,customer[input].customer_number);

	printf("the sale statstics of the customer are :");

	for(i=0;i<sale_index;i++)
	{
		if(sale[i].customer_number==input)
		{
			printf("Date of sale : %s\n",sale[i].date);
			printf("Item codes : \n");
			for(int j=0;j<sale[i].no_items;j++) printf("%d ",sale[i].code[i]);
			printf("\nAmount of items : \n");
			for(int j=0;j<sale[i].no_items;j++) printf("%d",sale[i].amount[i]);
				printf("\n\n");
		}
	}
}



int main()
{
	// Given the maximum number of customers and sales in the quesiton

	cust customer[20];
	sales sale[100];

	char input;
	int customer_index=0,sale_index=0;

	while(1)
	{
		scanf("%s",&input);

		if(input=='r')
		{
			Register_customer(customer[customer_index],customer_index);
			customer_index++;
		}

		if(input=='l')
		{
			List_customer(customer,customer_index);
		}

		if(input=='m')
		{			
			Modify_customer(customer,customer_index);
		}

		if(input=='s')
		{
			Sale(sale,sale_index);
			sale_index++;
		}

		if(input=='d')
		{
			Display_sale(sale,customer,sale_index);
		}

		if(input=='e')
		{
			printf("Thank you");
			break;
		}

	}

}