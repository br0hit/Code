/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 2: Question 2_b : Solving  with time complexity limited to O(nlogn)
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;


	//let n be the number of friends
	int friend_count,chicken_count;

	printf("Enter the number of friends: ");
	scanf("%d",&friend_count);

	printf("Enter the number of chicken pieces: ");
	scanf("%d",&chicken_count);

	int *chicken;

	chicken=(int *)malloc(chicken_count*sizeof(int));

	printf("Enter the consecutive weights (in grams) of the pieces: ");
	for(i=0;i<chicken_count;i++) scanf("%d",chicken+i);


		// Solving with time complexity O(nlogn) :


		// In case the total number of people are greater then the wrap cannot be split in any way possible
		// Just a if statement so complexity less that O(nlogn)

		if(friend_count+1>chicken_count) printf(" Cannot be divided in any possible way");


		// If the number of people are equal to the number of chicken pieces then you will get the chicken piece which will weigh the least 
		// Inside a single for() loop so complexity O(n) (< O(nlogn))

		else if(friend_count+1==chicken_count)
		{
			int i,min;

			for(i=0,min=9999;i<chicken_count;i++)
			{
				if(chicken[i]<min) min=chicken[i];
			}
			printf("%d",min);

		}



	return 0;

}