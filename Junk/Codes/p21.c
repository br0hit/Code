#include <stdio.h>
#include<stdlib.h>

int main()
{
	int N; 
	int *x;  // Defining an pointer to store the Array

	int i,j,check, freq,freq_max,freq_max_element;    // freq= freq of an element in each loop , other terms are self explanatory

	printf("Enter the value of N :");
	scanf("%d",&N);

	// Creating space for an integer array of size N

	x=(int *)malloc(N*sizeof(int));

	// Reading user data of N integers

	for(i=0;i<N;i++)
	{
		scanf("%d",x+i);
	}

	// Printing the input data

	 printf("The input Array is :\n");
	 for(i=0;i<N;i++) printf("%d ",*(x+i));

	 // Printing the frequencies

	 	printf("\n\nThe Array with their Respective frequencies is :\n");

	 for(i=0,freq_max=0,freq_max_element=0;i<N;i++)
	 {
	 	// First check with the previous elements if it is already repeated
	 	check=0;

	 	for(j=i-1;j>=0;j--)
	 	{
	 		if(*(x+j)==*(x+i))
	 		{
	 			check=1;
	 			break;  // Already counted in the freq in the prev steps
	 		}
	 	}

	 	if(check==0)
	 	{
	 		// Find all the next instances where the integer has been repeated

	 		for(j=i+1,freq=1;j<N;j++)  // Each element is present atleast once
	 		{
	 			if(*(x+j)==*(x+i)) freq++;
	 		}

		 	printf("Integer :%d  Frequency: %d\n",*(x+i),freq);
	 	}

	 	if(freq>freq_max)   // Finding the maximum frequency
	 	{
	 		freq_max=freq;
	 		freq_max_element=*(x+i);
	 	}
	 }

	 // Now since the use of Array is done we can finally free the space

	 free(x);

	 printf("\nThe most frequently occured element is : %d and its Frequency is : %d",freq_max_element,freq_max);

	 return 0;

}