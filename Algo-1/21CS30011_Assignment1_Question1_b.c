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
																										

	// Methood B: 

		// Making sure that the complexity never exceeds n i.e : There can never be even a single nested for loop



		// Worst case: 

		// If the numbers are continously decreasing we can never find i such that Wj>Wi for Cj>Ci which implies the answer will be none 

		for(i=0;i<n-1;i++)
		{
			if(City[i]<City[i+1]) break;
		}


		// Best case: 

		// if i==n-1 ; This implies that all the numbers are in the descending order and hence the output is None

		if(i==n-1) printf("None");

		// If the last element is greater than the first element then the algorithm can directly give the output as n-1

		if(City[n-1]-City[0]>0) printf("Maximum number of hops required = %d",n-1);


		// In other cases even if the initial value is maximum, it does not matter so since we have already considered the best case so we now have to check for the intermediate maximum

		// Let us define an auxillary array of the same size as the original and allocate space to store the indices of the maximum element for a particular element

		int *auxillary;
		auxillary=(int *)malloc(n*sizeof(int));

				int max;

		for(i=1,max=0;i<n;i++)
		{
			if(City[i]>max) max=City[i];
		}

	return 0;



}



