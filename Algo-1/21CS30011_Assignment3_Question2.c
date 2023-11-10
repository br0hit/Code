/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 3: Question 2 :  Maximizing the profit by using Greedy Algorithm

   Sweet Shop opens at 12
   Takes an hour to prepare

*/

#include<stdio.h>
#include<stdlib.h>

int min(int A[],int start, int end)
{
	int i;

	int min= 99999;  // Since all the costs are +ve we need to assume a very large min at the start

	while(start<end)
	{
		if(A[start]<min) min=A[start];

		start++;
	}

	return start;
}

int main()
{
	int i,j;
	int temp,index;


	int n;

	printf("Enter the number of sweet varietes: ");
	scanf("%d",&n);

	// let time and cost be 2 arrays fo size n time denoting the Latest time to deliver and Cost denoting the cost of each variety

	int *time,*cost;    

	// Dynamically allocating space for the time and cost array

	time=(int *)malloc(n*sizeof(int));
	cost=(int *)malloc(n*sizeof(int));

	printf("Enter the latest time to deliver each item: ");

	for(i=0;i<n;i++) scanf("%d",time+i);

	printf("Enter the cost (in Rupees) of preparing each item: ");

	for(i=0;i<n;i++) scanf("%d",cost+i);


	printf("-------\n");


	// Let us define a new array of the name variety to store the variety of the weet when the order will get changed 

	int *variety;

	variety=(int *)malloc(n*sizeof(int));

	// Now we will sort the time array in the order of times from maximum to minimum and will change the cost and variety array accordingly

	// Ideally we should do this by merge sort/quick sort so that the complexity will remain O(nlogn) but for simplicity over here let us sort this array with a simple bubble sort

	for(i=0;i<n;i++)
	{
		index=i;

		for(j=i+1;j<n;j++)
		{
			if(time[j]>time[index])
			{
				index=j;
			}
		}

		variety[i]=index;

		temp=time[i];
		time[i]=time[index];
		time[index]=temp;

		temp=cost[i];
		cost[i]=cost[index];
		cost[index]=temp;

	}


	// Maximizing the profit greedily : 
	
		/* In this application of greedy algorithm First we sort the array from the maximum time to the minimum time and then we can clearly see that to
		 greedily solve the problem we need to start from the maximum time and then slowly come back to 12pm, Note that at every point of 'time' ( Every hour)
		  we can choose any of the sweet variety which has not already been chosen and its time taken is less than the time at that partcular hour costs the least money out of the remaining  */
	
		// Example: Sorting the given array will give: 9,7,7,5,5,4,4,3,2,2
					
					/* So first we will select the sweet which will get finished by 9pm as no other sweet will come in its way and then
						 now the time will be reduced to 8pm and no sweet can be prepared so the time will then reduce to 7pm,
						 Now we can see 2 are available so we will choose the  one which has the least cost out and then time will now reduce to 6pm and Note: Now all the sweets which can be preapared after 6pm which have not already been chosen can be chosen and the time is now reduceed to 5pm and ..... */


	// Sorting the Sweets in the order of maximum time : 

	// For this we also have defined an array which returns the index of the minimum sweet variety 

		// Note that the last sweet variety( The sweet variety that will take the maximum time will definetly be on the list as that will not disturb any of the remaining variety which cost less than it and will also contribute to increase the total number of sweets)
	
	int count;

	int max,variety_index,total_cost;

	max=time[0];
	index=0;

	// Printing the sequence fo work done :

	while(1)
	{

		for(i=index,total_cost=0;time[i]>=max;i++);  // Initially we will start from the maximum hour

		variety_index=min(cost,index,i);

		printf("%d ,",variety[variety_index]);

		total_cost=total_cost+cost[variety_index];

		if(variety_index==index) index++;

		max--;

		if(max==time[n]) break;
	}

	printf("Total cost is %d",total_cost);

	return 0;

}