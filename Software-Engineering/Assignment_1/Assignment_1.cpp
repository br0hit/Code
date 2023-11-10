/* Name: Bannuru Rohit Kumar Reddy	
   Roll: 21CS30011
   Assignment-1 					*/

#include<iostream>
#include<cmath>

using namespace std;

int total_count;

typedef struct Polyn
{
	double coeff;
	int degree;

	struct Polyn * next;

}Polyn;


// Functions :

Polyn * Create_new_Polyn()
{
	cout<<"New polynomial created"<<endl;
	cout<<"Name of the polynomial: p"<<total_count<<endl;

	Polyn *P;
	P=NULL;

	return P;
}

void Show_polynomial(Polyn *p)
{
	int i=0;

	if(p==NULL) cout<<"Polynomial is currently empty"<<endl;
	else
	{
		cout<<"The polynomial is: "<<endl;

		Polyn *temp;
		temp=p;

		while(temp!=NULL)
		{
			cout<<temp->coeff<<"*"<<"x^("<<temp->degree<<")";
			while(temp->next!=NULL) cout<<"+";
			temp=temp->next;
		}
		//cout<<"\b \b";

	}
	
}

void Show_polynomials(Polyn **data)
{
	Polyn **temp;
	int i=0;
	temp=data;

	int input;

	if(total_count==0)
	{
		cout<<"Currently there are no polynomials"<<endl;
	}

	else
	{
		for(int i=0; i<total_count; i++)
		{
			cout<<i<<". p"<<i<<endl;
		}

		cout<<endl<<"Select the polynomial that you want to view : "<<endl;
		cin>>input;
		Show_polynomial(data[input]);

	}
}

void view_polynomials(Polyn **data)
{
	Polyn **temp;
	int i=0;
	temp=data;

	int input;

	if(total_count==0)
	{
		cout<<"Currently there are no polynomials"<<endl;
	}

	else
	{
		for(int i=0; i<total_count; i++)
		{
			if(*(data+i)!=NULL)
			cout<<i<<". p"<<i<<endl;
			else
			{
				cout<<i<<". p"<<i<<" - empty"<<endl;
			}
		}
	}
}

Polyn* addremoveterm(Polyn *p, int d, float c)
{
	Polyn *temp;
	Polyn *temp1;
	Polyn *prev;
	temp=p;

	int count;


	if(temp!=NULL)
	{
		count=temp->degree;
		prev=temp;

		while (count<=d && temp!=NULL)
		{
			prev=temp;
			temp = temp->next;
		}


		if(prev->degree==d)
		{
			prev->coeff += c;
		}
		else
		{
			temp1 = (Polyn *)malloc(sizeof(Polyn));

			temp1->degree=d;
			temp1->coeff=c;
			temp1->next=NULL;

			prev->next = temp1;
			temp1->next = temp;
		}

		return p;
	}

	else
	{
		temp1 = (Polyn *)malloc(sizeof(Polyn));

			temp1->degree=d;
			temp1->coeff=c;
			temp1->next = NULL;

			return temp1;
	}
	
}

// Polyn* addremoveterm(Polyn *p, int d, float c)
// {
// 	Polyn *temp,*prev;
// 	temp = p;

// 	Polyn *temp1;

// 	if(temp==NULL)
// 	{
// 		temp = (Polyn *)malloc(sizeof(Polyn));

// 		temp->coeff=c;
// 		temp->degree=d;
// 		temp->next=NULL;

// 		return temp;
// 	}

// 	else
// 	{
// 		while(temp!=NULL)
// 		{
// 			if(temp->degree==d) break;
// 			temp = temp->next;
// 		}

// 		if(temp->degree==d)
// 		{
// 			temp->coeff+=c;
// 		}

// 		else
// 		{
// 			temp=p;
// 			while(temp->degree>d && temp!=NULL)
// 			{
// 				prev=temp;
// 				temp=temp->next;
// 			}

// 			if(temp==NULL)
// 			{
// 				temp = (Polyn *)malloc(sizeof(Polyn));

// 				temp->coeff=c;
// 				temp->degree=d;
// 				temp->next=NULL;

// 				prev->next=temp;
// 			}

// 			else
// 			{
// 				temp1 = (Polyn *)malloc(sizeof(Polyn));

// 				temp1->coeff=c;
// 				temp1->degree=d;
// 				temp1->next=NULL;

// 				prev->next=temp1;
// 				temp1->next=temp;
// 			}
// 		}

// 	}

// 	return p;
// }

Polyn* addremoveterm(Polyn *p, int deg)
{
	Polyn *temp;
	Polyn *prev;
	temp = p;
	prev=temp;

	while(temp!=NULL && temp->degree!=deg)
	{
		prev=temp;
		temp=temp->next;
	}

	temp->coeff=0;

	return p;
}

Polyn* addremoveterm(Polyn *p, int x, int y, double epsilon)
{
	Polyn *temp;
	temp = p;

	while (temp!=NULL)
	{
		if(temp->coeff>0)
		{
			if(temp->coeff<epsilon) temp->coeff=0;
		}

		else
		{
			if(temp->coeff>epsilon) temp->coeff=0;
		}

		temp=temp->next;
	}

	return p;
}

double evaluate(Polyn *p, double x)
{
	double value=0;

	Polyn *temp;
	temp =p;

	while(temp!=NULL)
	{
		value += (temp->coeff)*pow(x,temp->degree);
		temp=temp->next;
	}

	cout<<"The value of the polynomial is: "<<value;
	return value;

}

Polyn* Add_Polynomials(Polyn *p1, Polyn *p2)
{
	int degree1,degree2;

	Polyn *temp;
	Polyn *final;
	final = NULL;

	temp=p1;

	while(temp!=NULL)
	{
		final = addremoveterm(final,temp->degree,temp->coeff);
		temp = temp->next;
	}

	temp=p2;

	while(temp!=NULL)
	{
		final = addremoveterm(final,temp->degree,temp->coeff);
		temp = temp->next;
	}


	return final;
}

// Polyn* derivative(Polyn *p)
// {
// 	Polyn *temp,*derivative;
// 	temp = p;

// 	derivative = (Polyn *)malloc(sizeof(Polyn));

// 	if(temp->degree==0 && temp->next==NULL)
// 	{
// 		derivative->coeff=0;
// 		derivative->degree=0;
// 		derivative->next=NULL;
// 	}

// 	if(temp->degree==0) temp=temp->next;

// 	while(temp!=NULL)
// 	{
// 		derivative = addremoveterm(derivative,temp->degree-1,temp->degree*temp->coeff);
// 		temp = temp->next;
		
// 	}

// 	return derivative;

// }

Polyn* derivative(Polyn *p)
{
	Polyn *temp,*derivative,*prev;
	temp = p;

	derivative = (Polyn *)malloc(sizeof(Polyn));
	Polyn *temp_,*temp_1;

	temp_ = derivative;

	if(temp->degree==0 && temp->next==NULL)
	{
		temp_->degree = 0;
		temp_->coeff = 0;

		temp_->next = NULL;

	}

	else
	{
		if(temp->degree==0) temp = temp->next;
		while(temp!=NULL)
		{

			temp_->degree = temp->degree-1;
			temp_->coeff = (temp->degree)*(temp->coeff);
			temp_->next= (Polyn *)malloc(sizeof(Polyn));

			prev=temp_;
			temp_ = temp_->next;
			temp=temp->next;
		}
		prev->next=NULL;

	}

	return derivative;

}

double zero_newton(Polyn *p, double x0, double epsilon)
{
	// Default value of epsilon told to be taken as 10^(-9)
	epsilon = pow(10,-9);

	Polyn *derivative_polyn;
	derivative_polyn = derivative(p);

	double x1;

	while(1)
	{
		x1 = x0 - (evaluate(p,x0)/evaluate(derivative_polyn,x0));

		if(x1-x0<epsilon) break;

		x1=x0;
	}

	return x1;

}


int main()
{
	Polyn **data;  // This stores all the data of the polynomials in the terms of their pointers

	// Lets assue that the number of polynomial pointers we are going to store is 10
	data = (Polyn **)malloc(10*sizeof(Polyn *));

	int input;
	int input_polynomial_index,second_index;


	cout<<endl<<"Enter the corresponding number to perform operation :"<<endl;

	while(1)
	{
		cout<<endl<<"1. Show polynomials"<<endl;
		cout<<"2. Create a new polynomial"<<endl;
		cout<<"3. Add new terms to a existing polynomial"<<endl;
		cout<<"4. Remove term of a particular degree"<<endl;
		cout<<"5. Remove all terms with absolute value less than epsilon"<<endl;
		cout<<"6. Evaluate the value of polynomial"<<endl;
		cout<<"7. Add 2 polynomials"<<endl;
		cout<<"8. Differentiate a polynomial"<<endl;
		cout<<"9. Calculate a root of the polynomial"<<endl<<endl;
		cout<<"Enter 10 to exit"<<endl;


		cin>>input;

		if(input==10) break;

		switch(input)
		{
			case 1:
			{
				Show_polynomials(data);
				break;
			}

			case 2:
			{
				Polyn *p;
				p = Create_new_Polyn();

				// if(total_count==0)
				// {
				// 	data = (Polyn **)malloc(sizeof(Polyn *));
				// 	total_count++;
				// }
				// else
				// {
				// 	total_count++;
				// 	data = realloc(data,total_count*sizeof(Polyn *));
				// }

				data[total_count] = p;
				total_count++;

				break;
			}

			case 3:
			{
				cout<<"Enter the number of the polynomial for which the terms are to be added"<<endl;
				view_polynomials(data);

				if(total_count!=0)
				{
					cin>>input_polynomial_index;

					int input_addterm_degree;
					double input_addterm_coeff;

					cout<<"Enter the degree followed by the coffecient for the new term"<<endl;

					cin>>input_addterm_degree>>input_addterm_coeff;

					data[input_polynomial_index] = addremoveterm(data[input_polynomial_index],input_addterm_degree,input_addterm_coeff);

				}

				break;
			}

			case 4:
			{
				int degree_removed;

				cout<<"Enter the number of the polynomial index and degreee of the term to be removed"<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index>>degree_removed;


				data[input_polynomial_index] = addremoveterm(data[input_polynomial_index],degree_removed);

				break;
			}

			case 5:
			{
				double epsilon;

				cout<<"Enter the value of epsilon: "<<endl;
				cin>>epsilon;
				cout<<"Enter the index of the polynomial for which the terms are to be removed: "<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index;

				data[input_polynomial_index] = addremoveterm(data[input_polynomial_index],0,0,epsilon);

				break;
			}

			case 6:
			{
				double value_x,output;

				cout<<"Enter the polynomial index at which the value is to be caluclated : "<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index;

				cout<<"Enter the value of x: "<<endl;
				cin>>value_x;

				output = evaluate(data[input_polynomial_index],value_x);

				break;
			}

			case 7:
			{
				cout<<"Enter the index of the polynomials which are to be added : "<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index>>second_index;

				Polyn * Added_polyn;
				Added_polyn = NULL;

				data[total_count] = Added_polyn;
				total_count++;

				data[total_count-1] = Add_Polynomials(data[input_polynomial_index],data[second_index]);
				cout<<"The sum of the two  polynomials p"<<input_polynomial_index<<"and p"<<second_index<<" is now stored in p"<<total_count-1<<endl;

				break;

			}

			case 8:
			{
				Polyn * derivative_polyn;
				derivative_polyn = NULL;

				cout<<"Enter the polynomial index whose derivative is to be caluclated : "<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index;

				data[total_count] = derivative_polyn;
				total_count++;

				data[total_count-1] = derivative(data[input_polynomial_index]);

				cout<<"The derivative of the polynomial is now stored in p"<<total_count-1<<endl;

				break;

			}

			case 9:
			{
				double x0,epsilon;
				double root;

				cout<<"Enter the polynomial index whose root is to be caluclated : "<<endl;
				view_polynomials(data);
				cin>>input_polynomial_index;

				cout<<"Enter the value of x0 (The starting point of newton's method"<<endl;
				cin>>x0;

				root = zero_newton(data[input_polynomial_index],x0,epsilon);

				cout<<"The root calculated from newtons method is: "<<root<<endl;

			}

		}

	}

	return 0;

}





