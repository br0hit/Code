#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int length,i;

	char *input;

	input=(char*)malloc(100*sizeof(char));

	printf("Enter the polynomial with white-spaces: f(x) =  ");
	scanf("[^\n]%s",input);

	for(length=0;*(input+length)!='\0';length++);

	// For printing the polynomial without whitespaces check each char and ignore the white spaces

	printf("\nPolynomial after removing white-spaces: f(x) = ");

	for(i=0;i<length;i++)
	{
		if(*(input+i)!=32) printf("%c",*(input+i));
	}

	return 0;

}