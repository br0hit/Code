#include<stdio.h>
#include<malloc.h>

int main()
{
	int n;

	scanf("%d",&n);

	int i;

	int *a;
	a=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}

	int min=9999;

	for(i=0;i<n;i++)
	{
		if(a[i]<min)
		min=a[i];
	}

	printf("%d",min);


}