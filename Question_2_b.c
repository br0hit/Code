/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Test_01: Question 02: Implementing Greedy strategy to obtain maximum points form minimum effort


*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,M;

	printf("Enter the number of assignments (n): ");
	scanf("%d",&n);
	printf("Enter the total number of hours left (M): ");
	scanf("%d",&M);

	// Let us define an Array m storing the number of hours needed for solving each assignment 
				// And an Arrray p storing the points of each assignment 

		// Dynamically allocating memory to it :

	int *m;
	m=(int *)malloc(n*sizeof(int));

	int *p;
	p=(int *)malloc(n*sizeof(int));

	// Taking input from the user : 

	int i,j;

	printf("Enter the number of points of each assignment: ");
	for(i=0;i<n;i++) scanf("%d",p+i);

	printf("Enter the number of hours needed to solve each assignment: ");
	for(i=0;i<n;i++) scanf("%d",m+i);

	printf("---------");

	// Minimum Effort needed by greedy strategy :

		// Defining a 2D array

		int P;

		for(i=0,P=0;i<n;i++) P=P+p[i];

		int T[n+1][P+1];


		// Note: In the question , Many of the values of the 2D array are told to be assumed infinty, This just means a very large value ( greater than P) so lets assume it to be 9999


		for(i=0;i<n+1;i++) T[i][0]=0;			// If we do not solve any Assignment then the attempted point is 0
		for(i=0;i<P+1;i++) T[0][i]=9999;		// In case no assignment is Considered then the Value of T[0][p] should be high so that we get the other boundary case in Min(M0,M1)


		// We also need to make sure that for all i if exactly p points cannot be achieved from the given set of points then T[i][p]=infinty (Large value which we are assuming to be 999)

			for(i=1;i<n+1;i++)
			{
				for(j=1;j<P+1;j++)
				{
					T[i][j]=9999;
				}
			}





			int temp1,temp2;

			for(i=1;i<n+1;i++)
			{
				for(j=1;j<P+1;j++)
				{
					if(j<p[i-1])
					{
						T[i][j]=T[i-1][j];
					}
					else
					{
						// Now Since the Total number of available points are greater than the points required for assignment i, This assignment can be solved

							// Case 1 : If we dont solve the ith Assignment :

								temp1=T[i-1][j];

							// Case 2 : If we solve the ith Assignment 

								temp2= T[i-1][j-p[i-1]]+m[i-1];


							// But we also have a boundary on the total number of hours so :

								if(temp2>M) T[i][j]=temp1;

								else
								{
									// For Getting the minimum Effort we need to find the minimum of both the values  : 

									if(temp1<temp2) T[i][j]=temp1;
									else T[i][j]=temp2;
								}
					}
				}
			}


		int max_p,corresponding_i;

		for(i=1,max_p=0;i<n+1;i++)
		{
			for(j=1;j<P+1;j++)
			{
				if(T[i][j]!= 9999)
				{
					if(j>max_p)
					{
						max_p=j;
						corresponding_i=i;
					}
				}
			}
		}

		printf("\n Maximum Points = %d",max_p+1 );
		printf("\n Minimum effort = %d",T[corresponding_i][max_p]);


		return 0;


}