#include <stdio.h>

int check(char input[])
{
	int i,length,count;

	//Caluclating the length of the string

	for(i=0,length=0;input[i]!='\0';i++) length++;

	for(i=0,count=0;i<length-1;i++)
	{
		if(input[i+2]-input[i]==1) count++;
	}

	return count;

}

void encode1(char input[])
{
	int i;

	for(i=0;input[i]!='\0';i++)
	{
		// Assuming the input string to be completely made of lower case alphabets from the given examples
		if(input[i]<'y') input[i]+=2;
		else if(input[i]=='y') input[i]='a';
		else input[i]='b';
	}
}

void encode2(char input[])
{
	char duplicate[20];
	int i,count;

	for(count=0;input[count]!='\0';count++) { duplicate[count]=input[count]; } // First we store the given input in another array

	for(i=0;i<2*count;i+=2)
	{
		input[i]='a';
		input[i+1]=duplicate[i/2];
	}
	input[i+2]='\0';

}

int main()
{
	char input[40]; // So that encode 2 has sufficient space evenf after adding the maximum no. of 'a'
	char duplicate[20]; // Using a duplicate since the output of encode 1 will change the original string
	int i,check_output;

	// Reading the input	

	printf("Enter the input string : ");
	scanf("%s",input);

	for(i=0;input[i]!='\0';i++) { duplicate[i]=input[i]; } // duplicate[i]='\0';} // Duplicaitng
	

	// Printing the input

	printf("\nThe string entered by the user is : %s\n",input);

	// check

	check_output=check(input);
	printf("Output of check is : %d",check_output);

	//encode1

	encode1(duplicate);
	printf("\nOutput of encode1 is : %s",duplicate);

	//encode2

	encode2(input);
	printf("\nOutput of encode2 is : %s",input);

	return 0;

}