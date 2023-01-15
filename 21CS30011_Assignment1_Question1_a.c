/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j;


	// Let n be the number of cities
	int n;

	printf("Enter the number of cities: ");
	scanf("%d",&n);    // Taking input of n

	// Dynamically allocating memory for an array named City to store the population data of n cities 
	int *City;

	City=(int *)malloc(n*sizeof(int));

	printf("Enter the populations: ");

	for(i=0;i<n;i++) scanf("%d",City+i);    // Taking input of the population of each city


		// for(i=0;i<n;i++) printf("%d\n",City[i]); Checking if the input is correct 


	// Method A : Brute Force Method of complexity O(n^2)

		// Defining max to store the maximum difference such that the population is increasing from Ci to Cj and the number of hops are maximum
		// temp is used for storing the hops in each subarray which is then compared with max

		int temp,max;


		for(i=0,max=0,temp=0;i<n;i++)
		{
			for(j=i+1;j<n && j!=n;j++)
			{
				if(City[j]>City[i])
				{
					temp=j-i;
				}

				if(temp>max) max=temp;
			}

		}

		if(max==0) printf("None");
		else { printf("Maximum number of hops required = %d",max); }



	return 0;

}



