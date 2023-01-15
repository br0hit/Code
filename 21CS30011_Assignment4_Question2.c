/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Assignment 4: Question 2 : Finding the Shortest Common Supersequence
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Modified_string( char * LCS, char *c)
{
	int i,j,k;

	for(i=0,j=0;i<strlen(c)-strlen(LCS);i++)
	{
		if(c[i]==LCS[j])
		{
			for(k=i;k<strlen(c)-1;k++)
			{
				c[k]=c[k+1];
				j++;
			}
		}
	}
}  




int  LCS_length( char * first, char * second )
{
		int i,j,k,m,n; 

	m=strlen(first);
	n=strlen(second);

	// First let us create a 2D array with m+1 rows and n+1 columns and name it S

	int **S;

	S=(int **)malloc((m+1)*sizeof(int *));
	for(i=0;i<m+1;i++) *(S+i) = (int *)malloc((n+1)*sizeof(int));

    // Initializing the first row and column to 0

		for(i=0;i<m;i++) S[i][0]=0;
		for(i=0;i<n;i++) S[0][i]=0;


			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(first[i]==second[i])
					{
						S[i,j]=S[i-1,j-1]+1;
					}

					else
					{
						if(S[i-1,j]>=S[i,j-1])
							{ S[i,j]=S[i-1,j] ;}

						else S[i,j]=S[i,j-1];

					}
				}
			}




	// Now to construct the LCS let us consider a new string of size 200 ( cannot exceed the sum of length of both strings which we assumed to have a maximum of 100)

		// Stsrting from the lest cell 

			char LCS[200];


			for(i=0;i<200;i++) LCS[i]=-1;

			i=m-1;j=n-1;
			k=0;

			while(i>=0||j>=0)
			{
				if(first[i]==second[j])
				{
					LCS[k]=first[i];

					i--;j--;
				}

				else 
				{
					if(S[i-1,j]>=S[i,j-1]) i--;
					else j--;
				}
			}

			for(i=0;LCS[i]!=-1;i++);


				return i;

}


int main()
{
	// Let the 2 strings be named first and second and lets assume the maximum size of these strings to be 100;

	char first[100],second[100];


	// Taking input from the user

	printf("Enter the first string: ");
	scanf("%s",first);
	printf("Enter the second string: ");
	scanf("%s",second);

	printf("---------\n");


	//  Finding the length of the SCS string and the sequence : 

	/*  Key Identification :  SCS Is nothing but the consecutive repetation of LCS of the smaller subsequences


	Since we already know how to find the LCS which is the largest common subsequence,
		 The SCS - THe shortest common supersequence will be Nothing but the consicutive addition of LCS until
		  we get a LCS whose size is less than 2 , in which case we have to just print the remaining strings 
		 

		Therefore :

		int SCS_Length

		  SCS(A,B) =

		  		while(strlen(LCS(A,B))>=2)
		  		{
					print(LCS(A,B));

		  		    SCS_Length = SCS_length + strlen(LCS(A,B));

					A = A-LCS(A,B);  // Original string - The String elements of LCS
					B = B-LCS(A,B);

		  		}

		  		SCS_Length= SCS_Length + strlen(A) + strlen(B)   // Once LCS<2 we need to add the remaining elements length of the elements which
		  															are not common to the length of the common elements 

		  		print(SCS_length);																											*/



		// First Finding the LCS of A and B

	int length_lcs;

	// while(1)
	// {
	// 	if(length_lcs<2)
	// 	{
	// 		length_lcs=length_lcs+strlen(first)+strlen(second);

	// 		break;
	// 	}
	// 	else 
	// 	{

	// 	}
	// }

	length_lcs=LCS_length(first,second);


     printf("%d",length_lcs);



}
