/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k;


	// Let the matrix have m rows and n columns
	int m,n;
	

	printf("Enter the number of rows of the matrix: ");
	scanf("%d",&m);
	printf("Enter the number of columns of the matrix: ");
	scanf("%d",&n);


	// Dynamically allocating the memory for a matrix having m rows and n columns

	int **M;

	M=(int **)malloc(m*sizeof(int *));  //Creating space for int* in each row
	for(i=0;i<m;i++)
		{
			*(M+i)=(int *)malloc(n*sizeof(int)); // Creating space for int in each column
		}


	// Filling the matrix of m rows and n columns with 0's and 1's to get the initial situation of the fruits

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&M[i][j]);
		}
	}

	printf("The resulting matrix will be : ");

	// Method A: Finding a Naive Solution

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(M[i][j]==0)
			{

				/* Now let us replace all the 1's in of that row and column in which 0 is present with -1 which we will replace with 0 again at the end
				   ** Note: We are not going to replace the 0's present in that row/column with -1 as that will result in loss of data as some other row may rot because of the 0 present which will not happen if we replace the 0 with -1 */

				for(k=0;k<m;k++) M[k][j]=-1;

				for(k=0;k<n;k++) M[i][k]=-1;

			}
		}
	}

	// Now all the -1's will be replaced by 0's to get the final resultant matrix and printing it 

	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			if(M[i][j]==-1) M[i][j]=0;

			printf("%d ",M[i][j]);  // Note that we are only printing the matrix only after replacing the arbitart value(In this case '-1') with 0

		}
	}


	return 0;

}