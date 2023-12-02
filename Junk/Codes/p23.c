#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,x;
	int i,j,max;

	int *M;
	int **N;

	printf("Enter the value of n :");
	scanf("%d",&n);

	N=(int **)malloc(n*sizeof(int *));
	M=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		scanf("%d",&x);

		N[i] = (int *)malloc(x*sizeof(int));
		M[i]=x;

	} 

	for(i=0,max=0;i<n;i++)
	{
		for(j=0;j<M[i];j++)
		{
			scanf("%d",&x);
			N[i][j]=x;

			if(x>max) max=x;
		}
	}

	printf("The largest integer is %d",max);






}