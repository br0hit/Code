/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Test_01: Question 01: Modified quicksort

   6 5 3 1 8 2 7 4 

*/

#include<stdio.h>
#include<stdlib.h>

// printf("1");

// Using Quick Sort : 


int Find_pivot(int *A, int start, int end)
{
	int pivot;

	pivot=A[start];

	int index1,index2;
	int temp=0;

	index1=start;
	index2=start+1;

	int i;

	for(i=index2;i<end+1;i++)
	{
		if(A[index2]>=pivot) index2++;

		else
		{
			if(index2==start+1)
			{
				index1++;
				index2++;
			}

			else
			{
				temp=A[index1+1];
				A[index1+1]=A[index2];
				A[index2]=temp;

				index2++;
				index1++;
			}
		}


	}

	A[start]=A[index1];
	A[index1]=pivot;

	return index1;

}

void Quick_sort(int *A, int start, int end)
{

	if(start==end) return;

	int pivot;

	pivot= Find_pivot(A,start,end);

	Quick_sort(A,start,pivot-1);
	Quick_sort(A,pivot+1,end);

}


int main()
{
	int n;

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	// Dynamically allocating space for an Array of size n

	int *A;
	A=(int *)malloc(n*sizeof(int));

	// Taking input from the user

	int i;

	printf("Enter the elements: ");
	for(i=0;i<n;i++) scanf("%d",A+i);

		printf("--------");
	printf("\nSorted sequence: ");


	// Sorting the Array using the modified version of the Quick Sort discussed in the problem : 


		// Quick_sort(A,0,n-1);

		// printf("Sorted Sequence: "); // for(i=0;i<n;i++) printf("%d ",A[i]);

}