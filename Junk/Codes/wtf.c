#include<stdio.h>
#include<stdlib.h>

int **MatMul(int **X, int **Y, int m,int p, int n)
{
	int **Z;
	int i,j,k;

	Z=(int **)malloc(m*sizeof(int *));

	 for(i=0;i<m;i++)
	 {
	 	*(Z+i)=(int *)malloc(n*sizeof(int));
	 }

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<p;k++)
			{
				*(*(Z+i)+j)=*(*(Z+i)+j)+X[i][k]*Y[k][j];
			}
		}
	}

	return Z;
}

int main()
{
	 int **X,**Y,**Z;

	 int m,n,p;
	 int i,j,count;

	 printf("Enter the values of m,n and p respectively: ");
	 scanf("%d%d%d",&m,&n,&p);

	 X=(int **)malloc(m*sizeof(int *));

	 for(i=0;i<m;i++)
	 {
	 	*(X+i)=(int *)malloc(p*sizeof(int));
	 }

 	 Y=(int **)malloc(p*sizeof(int *));

	 for(i=0;i<p;i++)
	 {
	 	*(Y+i)=(int *)malloc(n*sizeof(int));
	 }

	 Z=(int **)malloc(m*sizeof(int *));

	 for(i=0;i<m;i++)
	 {
	 	*(Z+i)=(int *)malloc(n*sizeof(int));
	 }

	 // Initializing both the arrays

	 for(i=0,count=0;i<m;i++)
	 {
	 	for(j=0;j<p;j++)
	 	{
	 		X[i][j]=count+1;
	 		count++;
	 	}
	 }

	 for(i=0,count=0;i<n;i++)
	 {
	 	for(j=0;j<p;j++)
	 	{
	 		Y[j][i]=count+1;
	 		count++;
	 	}
	 }

	 // Printing the final matrix

	 Z=MatMul(X,Y,m,p,n);

	 for(i=0;i<m;i++)
	 {
	 	printf("\n");
	 	for(j=0;j<m;j++)
	 	{
	 		printf("%d ",Z[i][j]);
	 	}

	 }
}