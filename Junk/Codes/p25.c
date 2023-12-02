#include <stdio.h>
#include<stdlib.h>
int data[20][20];

void findMax(int m,int n)
{
	int i,j,k;
	int sum,sum_max,maxsum_startpos_i,maxsum_startpos_j;

	for(i=0,sum_max=0,maxsum_startpos_j=0,maxsum_startpos_j=0;i<18;i++)
	{
		for(j=0,sum=0;j<18;j++)
		{
			for(k=0;k<3;k++) { sum=sum+data[i+k][j+0]+data[i+k][j+1]+data[i+k][j+2]; }		// Adding all the elements of a 3X3 submatrix

			// Finding the maximum sum and noting down the the position of the left most element

			if(sum>sum_max)
			{
				sum_max=sum;

				maxsum_startpos_i=i;
				maxsum_startpos_j=j;
			}
		}
	}

	// Printing the matrix

	printf("\nMax submatrix: \n");
	for(i=0;i<3;i++)
	{
		printf("		");
		for(j=0;j<3;j++)
		{
			printf("%d ",data[maxsum_startpos_i+i][maxsum_startpos_j+j]);
		}
		printf("\n")
;	}

	printf("Sum = %d",sum_max);

}

void findMin(int m,int n)
{
		int i,j,k;
	int sum,sum_min,minsum_startpos_i,minsum_startpos_j;

	for(i=0,sum_min=1,minsum_startpos_j=0,minsum_startpos_j=0;i<18;i++)
	{
		for(j=0,sum=0;j<18;j++)
		{
			for(k=0;k<3;k++) sum=sum+data[i+k][j+0]+data[i+k][j+1]+data[i+k][j+2]; 		// Adding all the elements of a 3X3 submatrix

			// Finding the maximum sum and noting down the the position of the left most element

			if(sum<sum_min)
			{
				sum_min=sum;

				minsum_startpos_i=i;
				minsum_startpos_j=j;
			}
		}
	}

	// Printing the matrix

	printf("\nMin submatrix: \n");
	for(i=0;i<3;i++)
	{
		printf("		");
		for(j=0;j<3;j++)
		{
			printf("%d ",data[minsum_startpos_i+i][minsum_startpos_j+j]);
		}
		printf("\n");
	}

	printf("Sum = %d",sum_min);

}

int main()
{
	int m,n;
	int i,j;

	printf("Enter the value of m and n respectively : ");
	scanf("%d%d",&m,&n);

	// First assigning each element of the  matrix 'data' the value 0

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			data[i][j]=0;
		}
	}



	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			data[i][j]=rand()%10+1;  // Giving a random integer between 0 and 10 in data
		}
	}

	printf("The Matrix 'data' is :\n");

	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%d  ",data[i][j]);
		}
		printf("\n");
	}

	findMax(m,n);
	findMin(m,n);

	return 0;

}