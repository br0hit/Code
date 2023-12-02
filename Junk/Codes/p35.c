	#include <stdio.h>
	#include <stdlib.h>



	void revcopysubmatrix(int** b,int** a,int I,int J,int n)
	{
	  int i,j,x,y;

		for(i=I,x=0;i<I+n;i++,x++)
		{
			for(j=J,y=0;j<J+n;j++,y++)
			{
				a[i][j]=b[x][y];
			}
		}
	}

		void copysubmatrix(int** b,int** a,int I,int J,int n)
	{
		int i,j,x,y;

		for(i=I,x=0;i<I+n;i++,x++)
		{
			for(j=J,y=0;j<J+n;j++,y++)
			{
				b[x][y]=a[i][j];
			}
		}
	}

	int main()
	{
		int n;
		int i,j;
		int **a;
		int **b,**c;

		printf("Enter the value of n : ");
		scanf("%d",&n);

		a=(int**)malloc(2*n*sizeof(int *));
		for(i=0;i<2*n;i++) { *(a+i)=(int*)malloc(2*n*sizeof(int));}

		printf("Enter the 2n elements in th matrix in the order in which the row is filled first: \n");

		for(i=0;i<2*n;i++)
		{
			for(j=0;j<2*n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}

		// Now for changing the original matrix into the given form we will be generating 2 more matrices of order nxn

		b=(int**)malloc(n*sizeof(int *));
		for(i=0;i<n;i++) { *(b+i)=(int*)malloc(n*sizeof(int));}

		c=(int**)malloc(n*sizeof(int *));
		for(i=0;i<n;i++) { *(c+i)=(int*)malloc(n*sizeof(int));}

		// Now we copy the rua and lla elements as per the q into b and c and then interchange them

		copysubmatrix(b,a,n,0,n);
		copysubmatrix(c,a,0,n,n);

		// Interchanging the positions of b and c

		revcopysubmatrix(b,a,0,n,n);
		revcopysubmatrix(c,a,n,0,n);

		// printing the final matrix

		printf("\nThe final matrix after interchanging the elements will be : \n");

		for(i=0;i<2*n;i++)
		{
			for(j=0;j<2*n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}