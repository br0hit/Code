/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 2: Question 2_a : Using a Brute force Method to solve 
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

		printf("\n-----\n");
		printf("Maximum weight of chicken piece(s) that you will get is: ");

		// Brute Force Method: 


		// In case the total number of people are greater then the wrap cannot be split in any way possible

		if(friend_count+1>chicken_count) printf(" Cannot be divided in any possible way");


		// If the number of people are equal to the number of chicken pieces then you will get the chicken piece which will weigh the least 

		else if(friend_count+1==chicken_count)
		{
			int i,min;

			for(i=0,min=9999;i<chicken_count;i++)
			{
				if(chicken[i]<min) min=chicken[i];
			}
			printf("%d",min);

		}

		// Logic to be applied in the brute force method: 

		/*  We have to divide the chicken in such a way that the least value of all the partitions is as high as possible
			Firstly we have to make the smaller* numbers in the array as large as possible keeping in mind that the total number
			of pieces do not go less the number of people, so for every smaller number in the array we have to add it either to
			the left or to the right */

	return 0;

}