#include<stdio.h>
#include<stdlib.h>

// int partition(int *A,int start, int end)
// {
// 	int pivot,temp;

// 	pivot=start;

// 	int i,j;

// 	i=start+1;j=start+1;
// 	temp=0;

// 	while(j<=end)
// 	{
// 		if(A[j]>A[start]) j++;

// 		else
// 		{
// 			temp=A[i];
// 			A[i]=A[j];
// 			A[j]=temp;

// 			i++;j++;

// 		}
// 	}

// 	if(i>end) i--;

// 	pivot=i-1;

// 		temp=A[i-1];
// 		A[i-1]=A[start];
// 		A[start]=temp;

// 	return pivot;
// }

// Partition second try

int partition(int *A, int start, int end)
{
	int pivot;

	pivot=A[start];

	int index1,index2;

	index1=start;
	index2=start+1;

	int i;
	int temp;

	for(i=index2;i<end+1;i++)
	{
		if(A[index2]<pivot)
		{
			if(index2==start+1)
			{
				index1=index2;
				index2++;
			}
			else
			{
				temp=A[index1+1];
				A[index1+1]=A[index2];
				A[index2]=temp;
				index1++;
				index2++;

			}
		}
		else
		{
			index2++;
		}
	}

	temp=A[index1];
	A[index1]=pivot;
	A[start]=temp;

	return index1;
}


void Quick_sort(int *A, int start, int end)
{
	int i;

	int pivot;

	if(start==end) return;

	pivot=partition(A,start,end);


	Quick_sort(A,start,pivot);
	Quick_sort(A,pivot+1,end);

}



int main()
{
	int i;

	int *A;

	int n;
	printf("Enter the number of integers: ");
	scanf("%d",&n);

	A=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++) scanf("%d",A+i);

	Quick_sort(A,0,n-1);

	for(i=0;i<n;i++) printf("%d",A[i]);

		return 0;
	
}