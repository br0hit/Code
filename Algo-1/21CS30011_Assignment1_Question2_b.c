/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j;


	// Let the matrix have m rows and n columns
	int m,n;

	printf("Enter the number of rows of the matrix: ");
	scanf("%d",&m);
	printf("Enter the number of columns of the matrix: ");
	scanf("%d",&n);


	// Dynamically allocating the memory for a matrix having m rows and n columns

	int **M;

	M=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++) *(M+i)=(int *)malloc(n*sizeof(int));

	// Filling the matrix of m rows and n columns with 0's and 1's to get the initial situation of the fruits

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&M[i][j]);
		}
	}

	printf("The resulting matrix will be : ");

	// Method B : Algortithm having a complexity of O(m*n) :

	// Having a complexity of O(m*n) implies that we can transverse the matrix any number of times but cannot implement a 'for' loop inside it of complexity m/n again

	/* Let us create 2 arrays of the size m and n ( the number of rows and columns of the input matrix ) and initialize all of them to 1

	   Now , when we transverse the matrix and find a 0(rotten fruit) in the spot M[i][j]; then we replace the i'th 1 in the row array we created with 0 and 
	   similarly the j'th 1 with 0; Now in this way once we transverse the whole matrix , all the rows and columns which have 0's in the matrix will also have 0's in the row and column matrix */
  

    // Dynamically allocating space for the 2 arrays and naming them row and column

	int *row;
	row=(int *)malloc(m*sizeof(int));
	int *column;
	column=(int *)malloc(n*sizeof(int));

	// initializing them to 1: 

	for(i=0;i<m;i++) row[i]=1;
	for(j=0;j<n;j++) column[j]=1;


	// The following for loop has a complexity of m*n :
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(M[i][j]==0)
			{
				row[i]=0;
				column[j]=0;
			}
		}
	}

	// Now we change all the rows which have 0's in the row column to 0


	// The following has a complexity of m*n
	for(i=0;i<m;i++)
	{
		if(row[i]==0)
		{
			for(j=0;j<n;j++) M[i][j]=0;
		}

	}

	// Similarly for columns


	// The following has a complexity of m*n
	for(j=0;j<n;j++)
	{
		if(column[j]==0)
		{
			for(i=0;i<m;i++) M[i][j]=0;
		}
	}


	/* As we can see that the complexity of all the for loops used never exceeded m*n so we can say that the final complexity of the algorithm used is O(m*n)
	  Hence proved */


	// Printing the final matrix :

	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d ",M[i][j]);
		}
	}


	return 0;

}