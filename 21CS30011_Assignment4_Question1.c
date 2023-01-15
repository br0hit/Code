/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 4: Question 1 : Finding the maximum possible download size
*/

#include<stdio.h>
#include<stdlib.h>

// Function used for Finding and returning Max[n] :

int Compare(int n, int *first, int *second, int *Max, int *index)
{


	int Max_sum_a,Max_sum_b;

	if(index[n]==1)   // If the Maximum sum till previous day has a download from the frist website at the end
	{

		Max_sum_a = Max[n]+first[n+1];                    // Downloading from the first website again
		Max_sum_b = Max[n]-first[n]+second[n+1];          // Remvoing the download from the prev day and now downloading from the second site 


			// Comparing both of them and reutrning the maximum : 

			if(Max_sum_a>Max_sum_b)
			{
				index[n+1]=1;
				return Max_sum_a;
			}

			else
			{
				index[n+1]=2;
				return Max_sum_b;
			}
	}

	if(index[n]==2)  // If the Maximum sum till previous day has a download from the second website at the end
	{

		Max_sum_a = Max[n] + first[n+1];            // Downloading from the first website again
		Max_sum_b = Max[n-1] + second[n+1];			/* Downloading from the second website again so Maxium sum till
													 n-2 date + blank + download from second website on nth day */


			// Comparing and returning Maximum :

			if(Max_sum_a>Max_sum_b)
			{
				index[n+1]=1;
				return Max_sum_a;
			}

			else
			{
				index[n+1]=2;
				return Max_sum_b;
			}

	}

}

// Function Used for storing the previous subproblems and returning the Maximum download size on day N :


int Max_Downlaod(int n, int *first, int *second, int *Max, int *index)
{
	if(Max[n-1]!=-1) return Max[n];

		int i;

		// Max[0] is the Maximum Size that can be downloaded on the first day which will just be the greater size of the frist and second website

		if(first[0]>second[0])
		{
			Max[0]=first[0];
			index[0]=1;
		}

		else
		{
			Max[0]=second[0];
			index[0]=2;
		}


	for(i=1;i<n;i++)
	{
		Max[i] = Compare(i-1,first,second,Max,index);
	}


	return Max[n-1];
}

int main()
{
	// Let n be the number of days
	int n;

	printf("Enter the number of days: ");
	scanf("%d",&n);


	// Allocating space to store the two sub-Arrays of Download Size of the first and second website

	int *first,*second;

	first=(int *)malloc(n*sizeof(int));
	second=(int *)malloc(n*sizeof(int));


	// Taking input from the user of Download Sizes

	int i;

	printf("Enter the download size restrictions of the first website (in GB):");
	for(i=0;i<n;i++) scanf("%d",first+i);

	printf("Enter the download size restrictions of the second website (in GB):");
	for(i=0;i<n;i++) scanf("%d",second+i);


	printf("--------------\n");
	printf("Maximum possible download size is ");



	// Logic of Dynamic programming to be used  :

	/*  First we try to find the optimal solution of the subproblem and then use it to solve the original problem

		Let us say the problem size is n, First we compute the maxium possible Download size for the problem size n-1
		and then we divide it into 2 cases: 

			point to remember : For the maximum download size for the subproblem the last day cannot be empty (no movie downloaded)
		
		Case 1:  Add the Download size of the first website on n^th day 
		Case 2: Remove the Download size from the n-1^th day and add the Download size of the second website
					( * This is because to download we can only download a movie from the second webiste if no
					      movie was downloaded on the previous day )


				 ***   Note:If the previous day which we removed had been from the second website, then we cannot directly
				      remove it and add download from the second website on the n^th day as it will leave 2 conecutive 
				      non downloading days , So in this case we have add the maxium possible sum until the n-2 days and add the 
				      second website download on the n^th day 
					      														*/	



		// Let us define a new array Max[n] which stores the Maximum Possible download size on till the n^th day
		// And an array index, Which stores whether the first website is used to download or second on the n^th day

		int *Max,*index;
		Max=(int *)malloc(n*sizeof(int));
		index=(int *)malloc(n*sizeof(int));

		// Initializing each element to -1

		for(i=0;i<n;i++) Max[i]=-1;
		for(i=0;i<n;i++) index[i]=-1;


			// Calling Function to Find Maximum Download size

			int Max_size;

			Max_size=Max_Downlaod(n,first,second,Max,index);



	printf("%d GB",Max_size);


}
