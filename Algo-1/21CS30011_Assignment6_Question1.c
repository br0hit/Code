/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 01: Finding the total number of minimum possible sweets 
 
*/

#include<stdio.h>
#include<stdbool.h>

int size;  // global variable declaring the size of the heap


// Utility function swap : 

void swap(int *A, int *B)
{
	int *temp;

	temp=A;
	A=B;
	B=temp;
}

bool IsNode(int n)
{
	return n<=size;
}

int root()
{
	return 1;
}

int leftChild(int n)
{
	return 2*n;
}

int rightChild(int n)
{
	return 2*n+1;
}


// Building the shiftDown function for the max heap

void shiftDown(int H[], int n)
{

	while(IsNode(leftChild(n)))
	{
			// Assuming a left child exists

			int child= leftChild(n);


		// If right child exists and is smaller than left child 

		if(IsNode(rightChild(n)) && (H[rightChild(n)]>H[leftChild(n)]))
		{
			child=rightChild(n);
		}

		if(H[n]<H[child])
		{
			int temp;

			temp=H[n];
			H[n]=H[child];
			H[child]=temp;
		}

		else break;

		n=child;

	}


}

// pop function to remove the root element 

void pop(int H[])
{
	// First replace the root with the last element of the heap

	H[root()]=H[size];

	size--;

	shiftDown(H,root());

}


void buildheap(int arr[], int H[], int number)
{
	// First storing the elements in the heap : 

	int i;

	for(i=0;i<number;i++) H[i+1]=arr[i];

		size=number;

	for(i=size/2;i>=1;i--)
	{
		shiftDown(H,i);
	}


}

int main()
{
	int number;

	printf("Enter the number of containers: ");
	scanf("%d",&number);

	int container[number];

	int i,k;

	// Taking the input from the user :

	printf("Sweets in each container = ");
 
	for(i=0;i<number;i++) scanf("%d",&container[i]);

	printf("k = ");

	scanf("%d",&k);



	// Using max heaps :

		/* The greedy approach as stated in the question is to take the container with maximum number of sweets in
			each round; but this has 2 restrictions : 

			1. The container from which the sweet has been chosen once cannot be chosen again 
			2. If we simply do it with an array then the time complexity for sorting is nlogn which we again have
				to perform k times


		    To avoid this we are going to use max heaps to store the array initially and then : 
		    Once the top container is chosen to take the sweets, we pop it and then store it in a new array which 
		    contains all the sweet containers from which the sweets are chosen  
		    																									*/


		// Implementation : 


		// First creating a max heap : 

		int H[number+1];

		buildheap(container,H,number);

		//for(i=0;i<size;i++) printf(" && %d &&  \n",H[i+1]);

		// Now after the maxHeap is built we will start removing elements from the root and pop them 

		int temp[number];  // Temporary array to store the popped out elements
		int min_remaining;	  // Maximum number of remaining sweets 



		for(i=0,min_remaining=0;i<k;i++)   // Taking the sweets K times 
		{
			temp[i] = H[root()];

			min_remaining+= (H[root()] - H[root()]/2 ) ;       // ( Adding the leftover sweets from the maximum container to the min_remaining ) 

			// printf(" ## %d ## \n",H[root()]);

			pop(H);  // Removing the largest element ( Root ) from the maxheap

		}

		// Printing the total remaining sweets : 

			// For this we have to halve all the number of sweets that are there in the temp array ( as we have already taken half of them)
			// and add them to the remaining elements in the maxheap

		for(i=0;i<size;i++)
		{
			min_remaining+=H[i+1];

			//printf(" $$ %d ## \n",H[i+1]);

		}

		// Now we have the total number of minimum remaining sweets possible 

		printf("Remaining total sweets: %d",min_remaining);


		return 0;

}