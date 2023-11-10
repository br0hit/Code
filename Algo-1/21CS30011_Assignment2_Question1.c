/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering


   Assignment 2: Question 1: Printing all possible sequences  
*/

#include<stdio.h>
#include<stdlib.h>


void print_index(char switch_data[9][5], int *S, int index, int total, char* sequence)
{
	int i,j;

	if(index!=total)  // once the index reaches the end we have to print the stored

		// Note: S[index] is the value of Switch at index position
		// and switch_data[S[index]] is the row in which the data of that particular switch is present
	{
		for(j=0;switch_data[S[index]][j]!='\0';j++)
		{
			sequence[index]=switch_data[S[index]][j];          
			print_index(switch_data,S,index+1,total,sequence);   // Recursively calling the function to store the sequence 
		}
	}

	else
	{
		i=0;
		while(sequence[i]!='\0'){ printf("%c",sequence[i]); i++;} // printing the stored sequence  
		printf(" ");

	} 
	
}

int main()
{
	int i;

	/*  Storing the predefined search codes in a 2D Matrix named switch_data
		Storing them in a Matrix will make it more easier and elegant to print than individual arrays
	    Note that the first row of the matrix is all null characters since the switch input starts from 1 and not 0 */


	// Filling up the matrix with predefined switch codes such that the characters in switch[n] will be in switch_data[n] (*nth row)

	char switch_data[9][5]={'\0','\0','\0','\0','\0','A','B','C','\0','\0','O','N','M','\0','\0','I','H','G','\0','\0','J','L','K','Z','\0','D','F','E','\0','\0','W','Y','X','\0','\0','T','U','V','S','\0','R','P','Q','\0','\0'};

	int n;

	printf("Enter the length of the switch sequence: ");
	scanf("%d",&n);

	// Dynamically allocating memory to storing the value of n switch codes in a array named S

	int *S;

	S=(int *)malloc(n*sizeof(int));

	printf("Enter the switch sequence : ");
	for(i=0;i<n;i++)scanf("%d",S+i);



		printf("----\n");
		printf("All possible messages are: ");


	// Recursively printing the codes :

		int index=0;  // Taking a integer to keep track of the position of the row 
		int total=n;  // Total is the length of the sequence 


		// Now we define a char Array of sufficient (Assuming the length of the sequence doesnt exceed 100) size to store each possible sequence which we find in the recursive function


		char *sequence;
		sequence=(char *)malloc(100*sizeof(char)); 

		for(i=0;i<100;i++)sequence[i]='\0';  // Initializing the char array to null char

		print_index(switch_data,S,index,n,sequence);  // Calling the recursive function to print the possible messages


	return 0;

}