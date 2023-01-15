/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 3: Question 1 :  FInding the maximum  number of captures using Greedy Algorithm	
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;


	int n,d;  	// n is the total number of people and d is the maximum distance which a dracula can reach

	printf("Enter the total number of people : ");
	scanf("%d",&n);

	printf("Enter the binary sequence of people and dracula: ");

	// Dynamically allocating space to store the Binary Sequence
	int *A;
	A=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++) scanf("%d",A+i);    

	printf("Enter the distance d: ");
	scanf("%d",&d);


	printf("-------\n");
	printf("Total number of captures = ");

	// Applying the greedy algorithm :

	/* The greedy way to solve this problem is to first check from the last dracula and start from the rightmost largest 
	   distance which the dracula can infect and then start coming back and then *if there is no one who can be infected on the right side of the dracula then start from the leftmost end 
	   of the dracula and then start going forward until that particular index, In this way maximum number of people can be infected */

	int j,start,check,count;

	for(i=n-1;i>=0;i--)
	{
		if(A[i]==1)
		{
			start=i+d;  // Start is the righmost end from which a dracula can infect

			if(start>n-1) start=n-1;  // *Important: Making sure that if the range of infection exceeeds the size of the array then the start poiint changes to the last element in the array

			for(j=start,check=0;j>i;j--)
			{
				if(A[j]==0)
				{
					A[j]=-1; count++;  // If a person is infected changing his index to -1 and increasing the value of the count
					check=1;           // Check is used to check if a person is affected to the right side fo the particular dracula or not
					break;             // We are breaking the loop if a person is infected because a dracula can only infect a single person
				}
			}

			if(check==0)               // In the case when the dracula cannot infect anyone on the right side then we start checking from the leftmost end
			{
				start=j-d;	// Leftmost end from which a dracula can affect

				if(start<0) start=0;  // Making sure that if the range of infection goes less than the size of the array then the start poiint changes to the first element in the array

				for(j=start;j<i;j++)
				{
					if(A[j]==0)
					{
						A[j]=-1; count++;
						break;
					}
				}
			}

		}
	}

	// for(i=0,count=0;i<n;i++)
	// {
	// 	if(A[i]==-1) count++;
	// }

	// Printing count which is the maximum number of infected people possible

	printf("%d",count);

	return 0;

}