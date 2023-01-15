/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering
*/

#include <stdio.h>
#include<stdlib.h>

int main()
{
	int n,*top,*bottom;
	int i;
	int check1=0,check2=0,count;

	printf("Enter the value of n: ");
	scanf("%d",&n);

	// Allocating space for storing the array of integers of top and bottom

	top=(int*)malloc(n*sizeof(int));
	bottom=(int*)malloc(n*sizeof(int));

	// Taking their input

	printf("top = ");
	for(i=0;i<n;i++) scanf("%d",(top+i));
	printf("bottom = ");
	for(i=0;i<n;i++) scanf("%d",(bottom+i));


	// checking if it is possible to arrange the dice such that the same number is faced oon every dice

		for(i=1,count=0;i<n;i++)
		{
			// Cheking if the dice from 2-n have the same number as the first top dice either at the top or at the bottom
			if((*top!=*(top+i)&&*top!=*(bottom+i))&&check1==0)
			{
				check1=1;
			}
			else
			{
				if(*top==*(bottom+i)) count++;
			}

			// *** Now if check==1, It implies that the top dice is not going to match with any of the remaining dice, Now we have to check the bottom. Else it impluies that it matches and the count we got is the no. of matches

			if((*bottom!=*(top+i)&&*bottom!=*(bottom+i))&&check2==0&&check1==1)
			{
				check2=1;
			}
			else
			{
				if(*(bottom)==*(top+i)) count++;
			}

			// If the loop does not break it implies that there is a possiblity of arranging them

		}

		if(check2==1&&check1==1) printf("-1");
		else 
			{
				if(count<=n/2) // Making sure that the value of n that we find is less than count/2 which is the minimum, if it is greater than that we just have to interchange the other set of dice 
				printf("%d\n",count-1);
			else printf("%d\n",n-count+1 );
		}

		return 0;



}