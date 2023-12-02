/* Name : Nitish kumar Singh
  Roll No: 21CS_nhiptabro  */

#include<stdio.h>
#include<stdlib.h>
// #include <string.h>

typedef struct
{
	// Since there is no upper limit on the character strings of username and password we are
	// Going to use pointers to store them

	char *username;
	char *password;

}user;

int strcmp_simplified(char *strg1,char *strg2)
{
	
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;
    }
}
 

int strlength(char *a)
{
	int i;

	for(i=0;*(a+i)!='\0';i++);
		return i;
}

void input(int n, user* x)
{
	int i,count=0,check=0,length;

	// First we will use a temporary null terminated string of fixed size to store the username and password; 
	// calucalte its length and then allocate the required amount of space to the username and password strings
	char *s;
	s=(char *)malloc(100*sizeof(char));  // Taking the fixed size to be 100

	while(n)
	{
		printf("Enter the username of person no.%d : ",count+1);
		scanf("%s",s);

		// First checking if the username already exists in the database

		while(1)
		{
			for(i=0;i<count;i++)
		{
			if(strcmp_simplified(s,(x+i)->username)==0)
			{
				printf("The enterted username already exists\nPlease enter a new username :");
				scanf("%s",s);
				continue;
			}
		}

		if(check==0) break;

		}

		// Finding out the length of the username
		length=strlength(s);

		// Allocating space for username and storing the entered username in it

		(x+count)->username=(char *)((length+2)*sizeof(char));  // Note: length+1 is used because we need to allocate space even for '\0' at the end
		(x+count)->username=s;

		// Taking password input; Allocating space for it and storing the password

		printf("Enter the password for the above username :");
		scanf("%s",s);

		length=strlength(s);

		(x+count)->password=(char *)((length+1)*sizeof(char));  // Note: length+1 is used because we need to allocate space even for '\0' at the end
		(x+count)->password=s;

		count+=1;  // Count is the total number of elements present until that point in the databse
		n-=1;

	}

}

void match(int n,user *x)
{
	int i=0,length,count;

	char *s;
	s=(char *)malloc(100*sizeof(char));  // Explained above

	// Taking the input of new username and password

	char *username_input,*password_input;

	while(1)
	{

	printf("Enter the username of person no :");
		scanf("%s",s);

	length=strlength(s);
	username_input=(char *)malloc((length+2)*sizeof(char));
	username_input=s;

	printf("Enter the password of person no: ");
		scanf("%s",s);

	length=strlength(s);
	password_input=(char *)malloc((length+2)*sizeof(char));
	password_input=s;


		for(i=0;i<n;i++)
		{
			if(strcmp_simplified(username_input,(x+i)->username)==0)
			{
				if(strcmp_simplified(password_input,(x+i)->password)==0)
					{ printf("login successfull"); break; break; }  // Break out of the for loop and the while loop

				else
				{
					while(1)
					{
						printf("Wrong password\nPlease enter the password again :");
						scanf("%s",s);

						length=strlength(s);
						password_input=(char *)malloc((length+2)*sizeof(char));
						password_input=s;

						if(strcmp_simplified(password_input,(x+i)->password)==0)
						{ printf("login successfull"); break; break; break; }  // Breaking out of the frist while loop of passowrd and then the remaining 2

					}
				}
			}
		}

		// Will only come to this point if the username is not in database so no need of adding a if case

		printf("The username does not exist in the Database, Please try again\n");

	}

}

int main()
{
	int n;
	user *x;  // Let x be the pointer of the first element of the array of users

	printf("Enter the value of n: ");
	scanf("%d",&n);

	// Dynamic memory allocation for n users :

	x=(user *)malloc(n*sizeof(user));

	// Taking input from the user and storing the data in array x
	input(n,x);

	printf("\nLogging in to the Database: \n");

	// Using the match function
	match(n,x);

	return 0;

}