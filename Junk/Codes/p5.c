#include <stdio.h>

int analyse(int A[],int size)
{
	int i,count,position,max_count,max_count_position;

	// Printing the Array

	printf("\nThe Input Array for analyzing is : \n(");
	for(i=0;i<size;i++) printf(" %d,",A[i]);
		printf(")\n");


	for(i=0,max_count=0,max_count_position=0;i<size-1;i++)
	{
		count=0;
		if(A[i+1]>A[i])
		{
			position=i;
			printf("(");
			while(1)
		{
			printf(" %d,",A[i]);
			 if(A[i+1]>A[i]) {i++;count++; if(i==size) break; }
			else break;
		}
		printf(")");
		}
		else i++;

		if(count>max_count)
		{
			max_count=count;
			max_count_position=position;
		}		
	}


	if(max_count==0) printf("\nThere is no increasing sequence present in the array");
		else
		{
			printf("\nThe largest increasing sequence is : \n(");
			for(i=max_count_position;i<max_count+max_count_position;i++) printf(" %d,",A[i]);
				printf(")");
			// printf("%d %d",max_count_position,max_count);
		}
}
int main()
{
	int A[]={3,5,7,8,2,3,4,5,1,2,3,4,5};
	analyse(A,13);

	return 0;

}