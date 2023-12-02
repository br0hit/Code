#include <stdio.h>
#include<stdlib.h>

typedef struct poly
{
	unsigned int coef;
	unsigned int degree;
	struct poly *next;
}poly;



int find_degree(char *input)
{
	int degree,temp;
	int i,j,length;

	for(length=0,degree=0,temp=0;*(input+length)!='\0';length++);

	for(i=0;i<length;i++)
	{
		if(*(input+i)=='x')
		{
			// if(*(input+i+1)>=48 && *(input+i+1)<=57) degree=*(input+i+1)-47;
			// else degree= *(input+i+2)

			for(j=1;j<length-i+1;j++)
			{
				if(*(input+i+j)>=48 && *(input+i+j)<=57) 
				{
					temp=*(input+i+j)-48;
					break;
					break;
				}
			}
		}

		if(temp>degree) degree=temp;
	}

	return degree;

}

void sanitise(char * input, poly* HEAD)
{
	poly *p,*prev;

	int i,j,k,length,check=0;

	for(length=0;*(input+length)!='\0';length++);

	printf("\nPolynomial after removing the ERROR: f(x) = ");

	// Given that the constant term is the first term of the polynomial
	
	HEAD->coef=*input;
	HEAD->degree=0;

	for(i=0;i<length;i++)
	{
		if(*(input+i) !='E'&& *(input+i)!='R' && *(input+i)!='O' )
			printf("%c",*(input+i));

		if(*(input+i)=='+')
		{
			check++;
			j=1;

			p=(poly*)malloc(sizeof(poly));

			while(1)
			{
 
				if(*(input+i+j)>48 && *(input+i+j)<=57 ) p->coef=*(input+i+j);

				if(*(input+i+j)=='x')
				{
					for(k=1;k<length-i+1;k++)
					{
						if(*(input+i+k)>=48 && *(input+i+k)<=57) 
						{
							p->degree=*(input+i+k)-48;
							break;
							break;
						}
					}
				}

				j+=1;
			}
			p->next=NULL;
			prev=p;
			if(check==0) HEAD->next=p;
			else prev->next=p;	
		}
	}

};

int main()
{
	poly *HEAD;

	HEAD=(poly*)malloc(sizeof(poly));

	char *input;

	input=(char*)malloc(100*sizeof(char));

	printf("Enter the polynomial with ERROR : ");
	scanf("%[^\n]s",input);

	printf("The degree of the polynomial is : %d",find_degree(input));

	sanitise(input,HEAD);

}