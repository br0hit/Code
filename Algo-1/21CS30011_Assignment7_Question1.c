/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 01: Decoding the message using the key given
 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 123

//  Note that the size of the hashTable is only 122 ( the ASCII value of z ) as we only need to store all of the english alphabet with their respective keys

/* The hashtable will have the ASCII value of the key itself ( For each alphabet of the 'message' which we want to decode ) as the index and we will just use an integer array to store
	the ASCII value of the corresponding alphabet which we have initially obtained from the key given by the user;

	i.e the hashfunction will give the ASCII value of key as output												 */

int hashTable[SIZE];


void createTable(char key[])
{
	int i=0;
	int ascii=97;  // ASCII value of a 

	while(key[i]!='\0')
	{
		if(hashTable[key[i]]==-1 && key[i]!=' ')  // Checking if the alphabet is already present or not
		{
			hashTable[key[i]]= ascii;

			i++;
			ascii++;
		}

		else i++;  // If the alphabet in the key is already covered or there is a space just move on to the next aphabet 

	}
}

void Decode_message(char message[])
{
	int i=0;

	while(message[i]!='\0')
	{
		if(message[i]!=' ')
		{
			printf("%c",hashTable[message[i]]);
			i++;
		}

		// If there is a space in the message it will be printed directly and then we will move on to the next character

		else
		{
			printf(" ");
			i++;
		}

	}

}


int main()
{
	// Assuming the size of the key and the input message which is to be decoded is not greater than 1000 chars

	char key[1000],message[1000];

	// Taking input from the user

	printf("key = ");
	//scanf("%s",key);
	fgets(key,1000,stdin);

	printf("message = ");
	//scanf("%s",message);
	fgets(message,1000,stdin);

	//printf("%s",message);
	printf("Decoded message : ");


	// Using the key to create a hashTable : 

		// First we initialize each integer of the hashTable to be -1 which indicates that currently no alphabet is stored in any index
		
		int i;

		for(i=0;i<SIZE;i++) hashTable[i]=-1;


		// Building the hashTable

			createTable(key);
		
		// Decoding the message by using the Table

			Decode_message(message);


	return 0;

}