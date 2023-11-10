/*,Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Quuestion 02 : Printing the k smallest index sums :
*/

// Note : In the solution below we have hard-coded both the arrays

#include<stdio.h>
#include<stdbool.h>


int size; // Global variable indicating the size of the array 


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


// Building the shiftDown function for the min heap

void shiftDown(int H[], int n)
{

	while(IsNode(leftChild(n)))
	{
			// Assuming a left child exists

			int child= leftChild(n);


		// If right child exists and is smaller than left child 

		if(IsNode(rightChild(n)) && (H[rightChild(n)]<H[leftChild(n)]))
		{
			child=rightChild(n);
		}

		if(H[n]>H[child])
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
	int m=64,n=60,k=10;

	int arr1[]={647,225,200,820,789,338,72,274,407,577,306,167,928,40,417,86,751,384,697,144,137,823,241,986,665,468,225,121,372,143,86,737,86,4,557,874,341,628,148,748,923,173,633,852,212,50,656,681,153,353,824,8,176,783,993,559,970,936,399,61,797,203,797,882};

	int arr2[]={206,354,757,547,700,623,14,623,514,646,194,444,414,849,125,566,202,948,292,96,732,285,374,702,940,772,762,737,974,559,620,898,631,96,445,331,437,177,672,951,822,866,395,955,715,520,240,636,187,532,731,637,535,823,339,475,314,819,931,7};


	// Solution :

	// First constructing an array of mn elements 
			// We can directly use double for loop as the timecomplexity we are looking for is O(mn)

	int A[m*n];

	int i,j,index;

	// Filling the Array A with all the products : 

	for(i=0,index=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			A[index]=arr1[i]+arr2[j];
			index++;
		}
	}


	// Now converting the Array into a min-heap :

	int H[m*n+1];

	buildheap(A,H,m*n);

	// Now printing the root and simultaniously remving it without loosing the heap strucutre

	for(i=0;i<k;i++)
	{
		printf("%d ",H[root()]);
		pop(H);
	}

	return 0;

}