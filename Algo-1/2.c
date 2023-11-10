
/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering
*/

#include <stdio.h>
#include<stdlib.h>

// First we try to Define a function which reverses a string "excluding the brackets whenever called upon"

void Reverse_string(char * c)
{
	int n=0,i,barricade=0;  // Defined a integer whose use is shown below
	char temp;

	// First we try to find the corresponding closed bracket fr the open bracket which is not as simple as *(c+n)==')' as there may be other open brackets and their corresponding closed brackets in the middle
	// Which is why we use barricade to differentiate between the required closed bracket and the imposters

	while(1)
	{
		if(*(c+n)=='(')
		{
			barricade++;
		}

		if(*(c+n)==')'&&barricade>0)
			barricade--;  // this makes sure that the barricade is 0 only when all the middle closed brackets are already transversed

		if(*(c+n)==')'&&barricade==0) break; 

		n++;
	}


	for(i=0;i<n/2;i++)
	{
		if(*(c+i)!=')'&& *(c+i)!='(')  // Interchanging the positions from the start and the end of the string which is present inside the bracketes that wwe chose initially 
		{
			temp=*(c+i);
			*(c+i)=*(c+n-i);
			*(c+n-i)=temp;	

		}
	}

}

int main()
{
	char *input;
	int input_size=0,i;


	input=(char *)(malloc(100*sizeof(char)));  // Assuming the input string size to be atmost 100
	printf("Input string: ");
	scanf("%s",input);

	while(*(input+input_size)!='\0') input_size++;  // FInding out the size of the input string 

	for(i=1;i<input_size-1;i++)
	{
		if(*(input+i)=='(')
		{
			Reverse_string(input+i);  // Whenever there is a open bracket we use the Reverse_string function which only changes the positons of the alphabets but does not interchange ) and (

		}
	}

	printf("Output string: ");  // We dont have to input the reversed string in a new string and waste data but instead just not print the paranthesis in the final reversed string 
	for(i=2;i<input_size-2;i++)
	{
		if(*(input+i)!=')'&&*(input+i)!='(')
			printf("%c",*(input+i));
	}


	return 0;

}