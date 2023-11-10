/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 02: Finding the teams which havent lost so far and which have lost exaclty once 
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Assuming that the maximum value of the unique id number of a team is 1000 we take the hashTable size to be 1000

#define SIZE 1000 


int hashTable[SIZE];


int main()
{
	int n;

	printf("Enter the value of n (No. of winning and losing teams) : ");
	scanf("%d",&n);

	// Defining a 2D Array with 2 columns and n rows :

	int A[n][2];

	// Taking input from the user : 

	printf("Input %d pairs of integers ( First the winning team and then the losing team ) : \n",n);

	int i,j,max_ID;

	// At the time of taking the input we will find the maximum value of the unique integer ID using max and then set it as the size of the hashTable

	for(i=0,max_ID=0;i<n;i++)
	{
		scanf("%d %d",&A[i][0],&A[i][1]);

		// Finding the maximum value of the unique ID : 

		if(A[i][0]>max_ID) max_ID=A[i][0];
		if(A[i][1]>max_ID) max_ID=A[i][1];
	}

	printf("%d\n",max_ID);

	int B[2][max_ID]; // 2D array in which first row will store the unique winners and second row will store the teams which have lost exactly once 

	// Initializing it to -1
	for(i=0;i<2;i++)
	{
		for(j=0;j<max_ID;j++)
		{
			B[i][j]=-1;
		}
	}


	// Using hashTable to find teams which have never lost and have lost only once :

	/*  We will implement the hashTable in the following way :

		The key of the hashTable will be the uniqueID of the team and will be stored at the index which is the value of the key itself 
		And the data which the hashTable will store is the number of defeats of the team

		i.e The hashfunction will take the key which is the unique number ID as the input and give the same as the output 

		This will help us identify whichever team has lost more than 1 match and also help us in filling the array which has only the winner teams  */



	// Defining a hashTable of size max_ID as that is the maximum index which we will use in the table

	int hashTable[max_ID];
	int unique_winners[max_ID];  // This array will store the number of wins of a unique ID

	// inititalizing unique_winners and hashTable to 0 ( As initally no one has even lost 1 match )

	for(i=0;i<max_ID+1;i++) unique_winners[i]=0;
	for(i=0;i<max_ID+1;i++) hashTable[i]=0;



		// ***NOTE : First we are going to fill the hastable with the number of defeats first so that we know 
			//    the information on all the teams which have lost so that we can exclude them from the unique winners list


	for(i=0;i<n;i++)
	{
		hashTable[A[i][1]]++;      // A[i][1] indicates the loosing ID's list, so now we are going to get a list of number of matches lost  
	}

	for(i=0;i<n;i++)
	{
		unique_winners[A[i][0]]++;
	}

	// Now we know the number of defeats of each ID

		// Storing the unique Winners in the 2D array and printing them : 

	int count;

	printf("[[");

	for(i=0,count=0;i<max_ID+1;i++)
	{
		if(unique_winners[i]>0 && hashTable[i]==0)  // No. of wins > 0 and no losses 
		{
			printf("%d,",i);
			B[count][0]=i;
			count++;
		} 
	}

	printf("\b],[");

	// Storing the teams which have lost exaclty one match in the output 2D array and printing them : 

	for(i=0,count=0;i<n;i++)
	{
		if(hashTable[A[i][1]]==1)
		{
			B[count][1]=A[i][1];
			count++;
			printf("%d,",A[i][1]);
		}
	}
	if(count>0) printf("\b");
	printf("]]");

}

