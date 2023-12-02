	#include <stdio.h>
	#include<stdlib.h>  // For using srand() to generate a random integer
	#include<time.h>    // For using time() as seed for the srand() function

	void Print_Matrix(int **X,int n)
	{
		int i,j;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",X[i][j]);
			}
			printf("\n");
		}
	}

	void Pattern1(int **X,int n)
	{
	   int i,j;


	   for(i=0;i<n;i++)
	   {

	   	// For the first half of the matrix there are 1's at the start
	   	if(i<n/2)
	   	{
	   		for(j=0;j<n/2;j++) X[i][j]=1; // Defining the first half of the 'row' as 1
	   	    for(j=n/2;j<n;j++) X[i][j]=0; // Defining the second half of the 'row' as 0
	   	}

	   else
	   {
	   	for(j=0;j<n/2;j++) X[i][j]=0; // Defining the first half of the 'row' as 0
	   for(j=n/2;j<n;j++) X[i][j]=1; // Defining the second half of the 'row' as 1
	   }

	  // For the second half of the matrix there are 1's at the last 

	   }
	}

	void Pattern2(int **X, int n)
	{
		int i,j;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i>=j) X[i][j]=1;
				else X[i][j]=0;
			}
		}
	}

	int BadEnc(int **X,int n,int k)
	{
		k=rand()%2;
		
		int i,j;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				X[i][j]= (X[i][j]+k)%2;
			}
		}

		return k;
	}

	void BadDec(int **X, int n, int k)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				X[i][j]= (X[i][j]+k)%2;
			}
		}
	}

	void GoodEnc(int **X, int **K,int n)
	{
		int i,j;
		int seed;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				srand(i-j); // since this value varies for every place

				K[i][j]= rand()%2;  // Generates a random k each time since we now used srand()

				X[i][j]= (X[i][j]+K[i][j])%2;

			}
		}
	}

	void GoodDec(int **X,int **K,int n)
	{
		int i,j;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				X[i][j]= (X[i][j]+K[i][j])%2;
			}
		}
	}


	int main()
	{
		int n;
		int k=0;
		int i,j,input;
		// int **x,**y;


		// Taking an input from the user
		printf("Please enter n: ");
		scanf("%d",&n);
		printf("\n\n");

		int ** M,**N;
		int ** K; // This is for storing the key for Good Decryption

		M=(int **)malloc(n*sizeof(int*));
		for(i=0;i<n;i++) M[i]= (int *)malloc(n*sizeof(int));

	   N=(int **)malloc(n*sizeof(int*));
		for(i=0;i<n;i++) N[i]= (int *)malloc(n*sizeof(int));

		K=(int **)malloc(n*sizeof(int*));
		for(i=0;i<n;i++) K[i]= (int *)malloc(n*sizeof(int));

		for(i=0;i<n;i++) { for(j=0;j<n;j++) K[i][j]=0; }

		Pattern1(M,n);  // Filling up the matrix

		// Printing the original matrix
		
		printf("Matrix with pattern-1: \n\n");
		Print_Matrix(M,n);

		Pattern2(N,n);  // Filling up the matrix

		// Printing the original matrix

		printf("\nMatrix with pattern-2: \n\n");
		Print_Matrix(N,n);

			while(1)
			{

				printf("\nEnter 1 to play with pattern-1 matrix\nEnter 2 to play with pattern-2 matrix\nEnter 3 to exit");
				printf("\n\nPlease Enter your choice: ");
				scanf("%d",&input);

				if(input==1)
				{

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

				}

				else if(input==2)
				{
									// Encrypting the matrix using Bad Encryption

					k=BadEnc(N,n,k);

					// Printing the encrypted matrix

					printf("\nBad Encrypted Matrix : \n\n");
					Print_Matrix(N,n);

					// Decrypting the matrix

					BadDec(N,n,k);

					// Printing the Decrypted matrix

					printf("\nMatrix after Bad Decryption : \n\n");
					Print_Matrix(N,n);

					// Encrypting the Matrix using Good Encryption

					GoodEnc(N,K,n);

					// Printing the encrypted matrix

					printf("\nGood Encrypted Matrix : \n\n");
					Print_Matrix(N,n);

					// Decrypting the matrix

					GoodDec(N,K,n);

					// Printing the Decrypted matrix

					printf("\nMatrix after Good Decryption : \n\n");
					Print_Matrix(N,n);
				}

				else if(input==3)
				{
					printf("Good Bye!");
					break;
				}
		}

		return 0;	
	}