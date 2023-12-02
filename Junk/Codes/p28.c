#include <stdio.h>
#include <stdlib.h>

void saddle(int **a, int rows, int columns)
{
	int i,j,k;
	int rowmax,rowmin,countmax,countmin,check;

	printf("The saddle points in the matrix are : \n");

	for(i=0;i<rows;i++)
	{
		for(j=0,rowmin=a[i][0],rowmax=a[i][0];j<columns;j++)
		{
			// Finding the maximum and minimum value in a row

			if(rowmin>a[i][j]) rowmin=a[i][j];
			if(a[i][j]>rowmax) rowmax=a[i][j];
		}

		for(j=0,countmax=0,countmin=0;j<columns;j++)
		{
			// Checking if the minimum or the maximum value in the matrix is repeated more than once

			if(rowmin==a[i][j]) countmin++;
			if(rowmax==a[i][j]) countmax++;
		}

		if(countmin==1)
		{
			for(k=0,check=0;(k<rows);k++)
			{
				if( (rowmin<=a[k][j] ) && (k!=i))
				{
					check=1;
					break;
				}
			}

			if(check==0) printf("%d ",rowmin);
		}

		if(countmax==1)
		{
			for(k=0,check=0;(k<rows);k++)
			{
				if((rowmax>=a[k][j]) && (k!=i) )
				{
					check=1;
					break;
				}
			}
			
			if(check==0) printf("%d ",rowmax);
		}
	}
}

int main()
{
	int **a;
	int rows,columns;

	int i,j;

	printf("Enter the number of rows in a : ");
	scanf("%d",&rows);
	printf("Enter the number of columns in a : ");
	scanf("%d",&columns);

	// Dynamic memory allocation

	a=(int **)malloc(rows*sizeof(int *));
	for(i=0;i<rows;i++) *(a+i)= (int *)malloc(columns*sizeof(int));

	// Filling up the array

		printf("Fill up the %d X %d matrix with integers : \n",rows,columns);

	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++) scanf("%d",(*(a+i)+j));
	}

	saddle(a,rows,columns);

	return 0;
}