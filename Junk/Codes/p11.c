#include <stdio.h>
#include<stdlib.h>  // For using srand() to generate a random integer
#include<time.h>    // For using time() as seed for the srand() function

void Print_Matrix(int M[][8],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
}

void Pattern(int M[][8],int n)
{
   int i,j;


   for(i=0;i<n;i++)
   {

   	// For the first half of the matrix there are 1's at the start
   	if(i<n/2)
   	{
   		for(j=0;j<n/2;j++) M[i][j]=1; // Defining the first half of the 'row' as 1
   	    for(j=n/2;j<n;j++) M[i][j]=0; // Defining the second half of the 'row' as 0
   	}

   else
   {
   	for(j=0;j<n/2;j++) M[i][j]=0; // Defining the first half of the 'row' as 0
   for(j=n/2;j<n;j++) M[i][j]=1; // Defining the second half of the 'row' as 1
   }

  // For the second half of the matrix there are 1's at the last 

   }
}

int BadEnc(int M[][8],int n,int k)
{
	k=rand()%2;
	
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			M[i][j]= (M[i][j]+k)%2;
		}
	}

	return k;
}

void BadDec(int M[][8], int n, int k)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			M[i][j]= (M[i][j]+k)%2;
		}
	}
}

void GoodEnc(int M[][8], int K[][8],int n)
{
	int i,j;
	int seed;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			srand(i+j); // since this value varies for every place

			K[i][j]= rand()%2;  // Generates a random k each time since we now used srand()

			M[i][j]= (M[i][j]+K[i][j])%2;

		}
	}
}

void GoodDec(int M[][8],int K[][8],int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			M[i][j]= (M[i][j]+K[i][j])%2;
		}
	}
}


int main()
{
	int n;
	int k=0;
	int i,j;

	// Taking an input from the user
	printf("Please enter n: ");
	scanf("%d",&n);

	int M[n][n];
	int K[n][n]; // This is for storing the key for Good Decryption

	for(i=0;i<n;i++) { for(j=0;j<n;j++) K[i][j]=0; }

	Pattern(M,n);  // Filling up the matrix

	// Printing the original matrix

	Print_Matrix(M,n);

	// Encrypting the matrix using Bad Encryption

	k=BadEnc(M,n,k);

	// Printing the encrypted matrix

	printf("\nBad Encrypted Matrix : \n\n");
	Print_Matrix(M,n);

	// Decrypting the matrix

	BadDec(M,n,k);

	// Printing the Decrypted matrix

	printf("\nMatrix after Bad Decryption : \n\n");
	Print_Matrix(M,n);

	// Encrypting the Matrix using Good Encryption

	GoodEnc(M,K,n);

	// Printing the encrypted matrix

	printf("\nGood Encrypted Matrix : \n\n");
	Print_Matrix(M,n);

	// Decrypting the matrix

	GoodDec(M,K,n);

	// Printing the Decrypted matrix

	printf("\nMatrix after Good Decryption : \n\n");
	Print_Matrix(M,n);


	return 0
;
	
}