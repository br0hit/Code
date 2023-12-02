#include <stdio.h>

typedef struct 
{
	char FirstName[15];
	char LastName[15];
}Name;

typedef struct
{
	float P,C,M,B;
	float total;
}Marks;

typedef struct
{
	Name name;
	char * RollNo;
	Marks marks;
}Student;


void TopFive(Student x[], int n)
{
	float a;
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i].marks.total<x[j].marks.total)
			{
				a=x[i].marks.total;
				x[i].marks.total=x[j].marks.total;
				x[j].marks.total;
			}
		}
	}

	printf(" The scores od top 5 Students in the record with their names and corresponding roll no.'s are are :");

	for(i=0;i<5;i++)
	{
		printf("\n%s %s   %s",x[i].name.FirstName,x[i].name.LastName,x[i],x[i].RollNo);
	}
}	



int main()
{
	int i,n=10;  // n is the number of students

	Student x[10]; // Creating a record of 10 students

	// Reading the data of the 10 students

	for(i=0;i<10;i++)
	{
		printf("\nEnter the first name of student %d : ",i+1);
		scanf("%s",x[i].name.FirstName);
		printf("Enter the last name of student %d : ",i+1);
		scanf("%s",x[i].name.LastName);
		printf("Enter the Roll No. Of student %d : ",i+1);
		scanf("%s",x[i].RollNo);
		printf("\nEnter the makrs of th student in P : ");
		scanf("%f",&x[i].marks.P);
		printf("Enter the makrs of th student in C : ");
		scanf("%f",&x[i].marks.C);
		printf("Enter the makrs of th student in M : ");
		scanf("%f",&x[i].marks.M);
		printf("Enter the makrs of th student in B : ");
		scanf("%f",&x[i].marks.B);

		// Total marks caluclation

		x[i].marks.total= x[i].marks.P+x[i].marks.C+x[i].marks.M+x[i].marks.B;
	}

	TopFive(x,n);  // Calling the top5 funciton

	return 0;

}