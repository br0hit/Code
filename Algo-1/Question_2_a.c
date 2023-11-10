/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Test_01: Question 02: Implementing Greedy strategy to obtain maximum points form minimum effort

   23 23 28 28 13 5 21 25 31 5

*/

#include<stdio.h>
#include<stdlib.h>


// Using Quick Sort : 


// int Find_pivot(int *A, int start, int end)
// {
// 	int pivot;

// 	pivot=A[start];

// 	int index1,index2;
// 	int temp=0;

// 	index1=start;
// 	index2=start+1;

// 	int i;

// 	for(i=index2;i<end+1;i++)
// 	{
// 		if(A[index2]>=pivot) index2++;

// 		else
// 		{
// 			if(index2==start+1)
// 			{
// 				index1++;
// 				index2++;
// 			}

// 			else
// 			{
// 				temp=A[index1+1];
// 				A[index1+1]=A[index2];
// 				A[index2]=temp;

// 				index2++;
// 				index1++;
// 			}
// 		}


// 	}

// 	A[start]=A[index1];
// 	A[index1]=pivot;

// 	return index1;

// }

// void Quick_sort(int *A, int start, int end)
// {

// 	if(start==end) return;

// 	int pivot;

// 	pivot= Find_pivot(A,start,end);

// 	Quick_sort(A,start,pivot-1);
// 	Quick_sort(A,pivot+1,end);

// }

int main()
{
	int n,M;

	printf("Enter the number of assignments (n): ");
	scanf("%d",&n);
	printf("Enter the total number of hours left (M): ");
	scanf("%d",&M);

	// Let us define an Array m storing the number of hours needed for solving each assignment 

		// Dynamically allocating memory to it :

	int *m;
	m=(int *)malloc(n*sizeof(int));

	// Taking input from the user : 

	int i,j,temp;

	printf("Enter the number of hours needed to solve each assignment: ");

	for(i=0;i<n;i++) scanf("%d",m+i);

	printf("---------");

	// Minimum Effort needed by greedy strategy :
		
		/* Since all the Assignments carry equal marks, For Obtaining the maximum marks through Minimum Effort we need to first solve the 
			Assignments which take the least amount of time and then go on in the increasing order of the time taken, For this here 
			we are first sorting the array in the order of increasing order of their times and then we will choose all the times such that
			the sum of them will ot exceed the total number of hours (M)

			  Therefore sum such that max_sum <M  */

		// Quick_sort(m,0,n-1);

		for(i=0;i<n-1;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(m[i]>m[j])
					{
						temp=m[i];
						m[i]=m[j];
						m[j]=temp;
					}
				}
			}



		int Min_Effort;

		for(i=0,Min_Effort=0;i<n;i++)
		{
			Min_Effort=Min_Effort+m[i];

			if(Min_Effort>M)       					// The case when the sum of the hours exceedes the total number of hours left 
			{
				Min_Effort=Min_Effort-m[i];			// Since we have considered the latest m[i] for it to cross the Total hours
													// to find the actual total hours we need to subract this
				break;
			}
		}

		printf("Minimum Effort needed (by greedy strategy) = ");
		printf("%d\n",Min_Effort );


	return 0;

}