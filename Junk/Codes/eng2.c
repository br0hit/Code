#include <stdio.h>

typedef struct
{
	int rows;
	int columns;

	int matrix[100][100];

}Matrix;

Matrix getMatrix(Matrix a)
{
	int i,j;

	printf("Enter the number of rows of the matrix: ");
	scanf("%d",&a.rows);
	printf("Enter the number of columns of the matrix: ");
	scanf("%d",&a.columns);

	for(i=0;i<a.rows;i++)
	{
		for(j=0;i<a.columns;j++)
		{
			scanf("%d",&a.matrix[i][j]);
		}
	}

	return a;

}

void printMatrix(Matrix b)
{
	int i,j;

	for(i=0;i<b.rows;i++)
	{
		printf("\n");
		for(j=0;j<b.columns;j++)
		{
			printf("%d ",b.matrix[i][j]);

		}
	}
}

Matrix multiply(Matrix a, Matrix b)
{
	int i,j,k;

	Matrix c;

	c.rows=a.rows;
	c.columns=b.columns;

	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<b.columns;j++)
		{
			for(k=0;k<a.columns;k++)
			{
				c.matrix[i][j]=c.matrix[i][j]+a.matrix[i][k]*b.matrix[k][j];
			}
		}
	}

	return c;
}

Matrix add(Matrix a , Matrix b)
{
	Matrix c;

	c.rows=a.rows;
	c.columns=a.columns;

	int i,j;

	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.columns;j++)
		{
			c.matrix[i][j]=a.matrix[i][j]+b.matrix[i][j];
		}
	}

	return c;
}

int main()
{
	Matrix a;

	a=getMatrix(a);

	printMatrix(a);

}