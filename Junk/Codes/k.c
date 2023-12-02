#include <stdio.h>

int main()
{
	int i,j,index,rain;
	int n;

	for(index=0,rain=0;index<n;index++)
	{
		for(i=index+1;i<n;i++)
		{
			if(height[i]>=height[index])
			{
				for(j=index+1;j<i;j++)
				{
					rain=rain+height[index]-height[j];
				}
				index=i;
				

			}

		}
	}
}