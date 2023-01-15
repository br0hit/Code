/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   // Lab Test 02

   Question 02 : Finding the maximum possible average pass ratio by using Heap/priority queue 
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20


int classes[SIZE][2];   // Defining a 2D array classes having n rows and 2 columns
int size;				// Global variable indicating the sie of the heap


// Utility functions :

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

// Defining a function key_val which will give us the 'key' ( differnce in ratio on the addition of a new student which will be used to compare and order the max-heap)

float key_value(int n)
{
	float val_1,val_2;

	val_1 = (float)classes[n][0]/classes[n][1];

	val_2=((float)classes[n][0]+1)/(classes[n][1]+1);

	return (val_2-val_1);
}



void shiftDown(int H[], int n)
{

	while(IsNode(leftChild(n)))
	{
			// Assuming a left child exists

			int child= leftChild(n);


		// If right child exists and its key value is larger than left child 

		if(IsNode(rightChild(n)) && (key_value(rightChild(n))>key_value(leftChild(n))))
		{
			child=rightChild(n);
		}

		if(key_value(n)<key_value(child))
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

void buildheap(int H[], int number)
{
	// First storing the elements in the heap : 

	int i;

	for(i=0;i<number;i++) H[i+1]=i+1;

		size=number;

	for(i=size/2;i>=1;i--)
	{
		shiftDown(H,i);
	}
}

int main()
{
	int i;

	// Let the total number of classes be n and the number of extra students be extraStudents

	int n,extraStudents;

	printf("Enter the total number of classes : ");
	scanf("%d",&n);

	printf("Enter the details of %d classes with the no. of students who pass and the total number of students respecively : \n",n);

	for(i=1;i<n+1;i++)
	{
		scanf("%d %d",&classes[i][0],&classes[i][1]);
	}

	printf("Enter the number of extra students: ");
	scanf("%d",&extraStudents);


	// Using heaps to find the maximum average pass ratio : 

	// Let us define the binary heap as H
	int H[n];

	/* The heap will only store the indexes of the classes ( Lets take the class whose data was first entered as 1 and next as 2..) 

	/* Here the priority order of the heap ( Which will be a max heap) will be based on the difference of the class ratio on the addition of a extra student 
		As, at every instant we will add a new student to the class which will give us the maximum increase in the ratio so that 
		the average ratio of all the classes can be maximized 																	*/

	// Building the heap :

	buildheap(H,n);

	// Now as we have created a max heap, we will keep on addingg extra students to the top of the heap and use shiftdown to reoder the heap

	int index;

	for(i=0;i<extraStudents;i++)
	{
		index=H[1];

		classes[index][0]++;
		classes[index][1]++;

		shiftDown(H,1);

	}

	// calucalting the ratio :

	float max_avg,avg;

	for(i=0,max_avg=0,avg=0;i<n;i++)
	{
		avg = (float)classes[i+1][0]/(1.0*classes[i+1][1]);

		max_avg+=avg;

	}

	printf("\nThe maximum posible average pass ratio is : %f",max_avg/n);

	return 0;
}