#include<stdio.h>

void readlists(	int A[],int B[],int n,int m)   // Function of reading arrays A and B
{
	int i;

	printf("Enter the elements of the  array A :");
	for(i=0;i<n;i++) scanf("%d",&A[i]);               // Using for loop to scan the n elements of array A
	printf("Enter the elements of the  array B :");
	for(i=0;i<m;i++) scanf("%d",&B[i]);               // Using for loop to scan the m elements of array B

}

void printlist( int A[],int B[],int n,int m)  // Function for printing the elements in A and B
{
	int i;

	printf(" Elements of Array A are : ");
	for(i=0;i<n;i++) printf("%d ",A[i]);
	printf("\n Elements of Array B are : ");
	for(i=0;i<m;i++) printf("%d ",B[i]);

}

int search( int A[],int B[],int C[],int n,int m)  // Search funtion which prints the no. of occurances and also the position of each occorance and stores it in Array C
{
	int i,j,check,count;

	//Printing the position of the occurances

	printf("\nThe positions of the occurances are: ");

	for(i=0,count=0;i<n-m+1;i++)
	{
		check=0; 

		for(j=0;j<m;j++)
		{
			if(A[i+j]==B[j]) check=1;
			else { check=0; break;}
		}

		if(check==1)
		{
			C[count]=i+1;
			printf("%d ",C[count]);
			count++;
		}
	}

	printf("\nNumber of occorances of B in A are : %d",count);

	return count;
}

int main()
{
	int m,n;
	int A[100],B[100],C[100],D[100];
	int no_matches,i,j,k,count;

	//Reading the values of m and n

	printf("Enter the value of n :");
	scanf("%d",&n);
	printf("Enter the value of m :");
	scanf("%d",&m);

	//Displaying the values

	printf("n=%d m=%d\n",n,m );

	// Calling the function to read the arrays

	readlists(A,B,n,m);

	// Calling function to print the arrays

	printlist(A,B,n,m);

	// Searching for common matches and storing the number of matches in no_matches and  the positions in C
	// Not that 'search' function is defined in such a way that it prints out the number of occorances and the positions simultaneously for it to be easier for further parts

	printf("\n\nFor the main sequence of B: ");
	no_matches=search(A,B,C,n,m); 


	printf("\n");
	for(i=0,count=0;i<m;i++)  // Running it for m numbe rof times where m is no. of elements in set B , In first iteration we will consider the subsequece having 1 element and then 2 so on....
	{
		for(j=0;j<m-count;j++)  // Determing the number of times a loop should be run and 'search' function to be called for a subsequence of B having 'i+1' elements
		{
			for(k=0;k<count+1;k++) D[k]=B[k+j];  // Storing the elements in a new array D which will be modified each time

			// Printing the subsequence for which the 'search' function is called for better clarity

			printf("\nFor the subsequence of B which is given by : ");
		    for(k=0;k<count+1;k++) printf(" %d",D[k]); 

			search(A,D,C,n,count+1);  // Calling the search function which also prints the number of times and the positions of occorances and stores it in C, Note that here we are calling B which is the modified subsequence of B having 'count+1' no. of elements
		}
		count++;

	}



	return 0;

}