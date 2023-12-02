#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct entry
{
	char var[40]; 
	int val ;
} dictnode;

typedef struct
{
	dictnode *dictionary ;
	int numentry ; // Stores the current number of entries in the dictionary
	int dsize; // The size of the dictionary[] array which defines the maximum number entries
} DICT;

DICT * createdict(int dictsize)
{
	DICT *pdictionary;

	pdictionary=(DICT *)malloc(sizeof(DICT));  								// First alloting space to the DICT structure

	pdictionary->dsize=dictsize;  										    // Initializing dsize which stores the maximum number of entries which is initially defined as dictsize
	pdictionary->dictionary=(dictnode *)malloc(dictsize*sizeof(dictnode));  // Allocating required space for dictionary
	pdictionary->numentry=0; 												//Initial number of entries stored =0

	return pdictionary;
}

dictnode makeentry(char var[],int val)
{
	dictnode newentry;

	int i;

	for(i=0;var[i]!='\0';i++)
	{
		newentry.var[i]=var[i];
	}
	newentry.var[i]='\0';

	newentry.val=val;

	return newentry;
}

void add1entry(dictnode newentry, DICT * pdictionary)
{
	int i,check;

	// First checking if the maximum capactiy of the dict is reached

	if(pdictionary->numentry>=pdictionary->dsize) 
	{
		printf("The maximum limit of the dictionary is reached, No new entries can be made");
	}

	else
		{
			for(i=0,check=0;i<pdictionary->numentry;i++)
			 {
			  if(strcmp(newentry.var,pdictionary->dictionary[i].var)==0)  // Checking if a entry with the same variable name exists
			  {
			  	pdictionary->dictionary[i].val=newentry.val;               // Updating the value with the new value input by the user
			  	check=1;						 
			  	break; 	
			  } 
			 }

			 if(check==0)
			 {
			 	pdictionary->dictionary[pdictionary->numentry]=newentry;  // Otherwise creating a new entry in the dictionary
			 	pdictionary->numentry++;  					// Increasing the numentry(No. of entries in the dictionary) by 1
			 }
		}
}

void printentry(DICT *pdictionary,char var[])
{
	int i;

	for(i=0;i<pdictionary->numentry;i++)
	{
		if(strcmp(pdictionary->dictionary[i].var,var)==0)
		 printf("The Entry of the word %s is as follows:\nPosition in the dictonary: %d\nNumber of times it is repeated in the dictionary: %d ",var,i,pdictionary->dictionary[i].val);	
	}

}

void delentry(DICT *pdictionary, char var[])
{
	int i,pos;
	
	// Finding the position of var in the dictionary and naming its position as pos

	for(i=0,pos=0;i<pdictionary->numentry;i++)
	{
		if(strcmp(pdictionary->dictionary[i].var,var)==0)
		{
			pos=i;
			break;
		}
	}

	// Moving all the entries to the right side of the pos to the left by 1 to remove the entry at pos

	for(i=pos;i<pdictionary->numentry-1;i++)
	{
		pdictionary->dictionary[i]=pdictionary->dictionary[i+1];
	}

	// Since one of the entry is deleted numentry value will also decrease by 1

	pdictionary->numentry--;
}

void printdict(DICT *pdictionary)
{
	int i;
    
    // printf("All the current entries with their corresponding values present in the Dictionary are : \n");
	for(i=0;i<pdictionary->numentry;i++) printf("     %s %d\n",pdictionary->dictionary[i].var,pdictionary->dictionary[i].val);
}

// Now defining the user defined functions and the table

int main()
{
	int dictsize,i,check;

	dictnode newentry; // To store the dict input after the function is specified

	char *input_function;  // To store the function input

	input_function=(char *)malloc(6*sizeof(char));  // Since the maximum 'function input which the user can give is print which has 5 letters'

	char *input_var; int input_val;  // Variables for storing the input variables and values

	input_var=(char *)malloc(40*sizeof(char));  // Assuming the maximum alhapbet count of a entry cannot exceed 40

	char add[]="add" ,find[]="find", del[]="del", print[]="print", quit[]="quit" ;  // char defined to use strcmp with input_function


	printf("Enter the value of dictsize (Will create a dictionary for thhe user which can hold dsize no. of entries) :");
	scanf("%d",&dictsize);

	// Creating a dictonary structure named DICT 

	DICT * pdictionary;

	pdictionary=createdict(dictsize);

	printf(" Now the user can perform operations such as add, find, delete, print, quit : \n");

	while(1)
	{

		scanf("%s",input_function);

		if(strcmp(input_function,add)==0)
		{
			scanf("%s",input_var);
			scanf("%d",&input_val);

			// Making a new entry to store the input

			newentry=makeentry(input_var,input_val);

			// Adding the entry to the dictionary

			add1entry(newentry,pdictionary);
		}

		if(strcmp(input_function,find)==0)
		{
			scanf("%s",input_var);

			for(i=0,check=0;i<pdictionary->numentry;i++)
			{
				if(strcmp(input_var,pdictionary->dictionary[i].var)==0)
				{
					printf("     %s %d\n",pdictionary->dictionary[i].var,pdictionary->dictionary[i].val);   // Comparing the input string with the strings present in the dictionary
					check=1;
					break;
				}
			}

			if(check==0) printf("     %s not found\n",input_var);
		}

		if(strcmp(input_function,del)==0)
		{
			scanf("%s",input_var);

			delentry(pdictionary,input_var);
		}	

		if(strcmp(input_function,print)==0)
		{
			printdict(pdictionary);
		}

		if(strcmp(input_function,quit)==0)
		{
			printf("     Bye");
			break;
		}

	}

	return 0;

}