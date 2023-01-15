/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   // Lab Test 02

   Question 03 : Checking if 2 arrays are same or not using hash tables

*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int hashTable[SIZE];

int Hash(int key)
{
	return key%SIZE;
}

void push(int n)
{
	int index;

	index=Hash(n);

	while(hashTable[index]!=-9999)
	{
		index++;
		index%SIZE;
	}

	hashTable[index]=n;
}

int Search(int n)
{
	int index,sum=0;

	index=Hash(n);

	if(hashTable[index]==n)
	{
		hashTable[index]=-1000;
		return 0;
	}


	else
	{
	   while(hashTable[index]!=n && sum<=9)
	   {
	   	  index++;
	   	  index%SIZE;

	   	  sum++;
	   }

	   if(sum<9)
	   {
	   		hashTable[index]=-1000;
	   		return 0;
	   }
	   else return 1;

	}

}

int main()
{
	// Let the number of elements in both the arrays be n

	int n;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);

	// Taking input of A and B from the user:
	int A[SIZE],B[SIZE];

	int i;

	printf("Enter the elements in Array A: ");
	for(i=0;i<n;i++) scanf("%d",&A[i]);

	printf("Enter the elements in Array B: ");
	for(i=0;i<n;i++) scanf("%d",&B[i]);


	// Using a Hash table which uses Linear probing

	// Initializing the hashTable to -9999

		for(i=0;i<SIZE;i++) hashTable[i]=-9999;

	// Inserting the elements of the first Array A into the hashTable

		for(i=0;i<n;i++)
		{
			push(A[i]);
		}

		//for(i=0;i<SIZE;i++) printf("%d\n",hashTable[i]);

	// Checking if all the elements of Array B are there in the hashTable

		// Note : If a node is already transversed in the hashtable we have to delete it so that we can identify the common elements which are probed to other places in the hashtable
		// Lets indicate a deleted index at the hashtable with the value -1000

		int temp;

		for(i=0,temp=0;i<n;i++)
		{
			temp=Search(B[i]);

			if(temp==1)
			{
				break;
			}
		}


		if(temp==1) printf("Both the arrays have Different elements\n");
		else printf("Both the arrays have exaclty the same elements \n");


		return 0;

}
