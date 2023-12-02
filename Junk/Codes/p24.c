#include <stdio.h>

void expenditure(float A[][25], float B[][25], float C[], int m, int n)
{
	int i,j;

	for(i=0,c[i]=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i]=c[i]+A[i][j]*B[j][i]
		}
	}

	printf("The final expenditure in the m months is : ");
	for(i=0;i<m;i++) printf("%f ",c[i]);
}

int main()
{

}