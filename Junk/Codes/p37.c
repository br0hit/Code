#include <stdio.h>

struct Student
{
	char rollNo[10];
	float marks;
	int rank;
};

void sort(struct Student *record, int n)
{
	int i,j;
	struct Student *temp;

	temp=(struct Student *)malloc(sizeof(struct Student));

	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if((record+j)->marks<(record+j+1)->marks)
			{
				*temp=*(record+j);
				*(record+j)=*(record+j+1);
				*(record+j+1)=temp;
			}
		}
	}
}

void rank(struct Student *record, int n)
{
	int i,count;
	float prev_marks;

	for(i=0,count=1;i<n;i++)
	{
		if(i>1)
		{
			if(prev_marks==(record+i)->marks)
			{
				(record+i)->rank=count;
			}

			else 
			{
				prev_marks=(record+i)->marks;
				(record+i)->rank=count+1;
				count+=1;
			}
		}

		else
		{
			prev_marks=record->marks;
			record->rank=1;
		}
	}
}

void search(struct Student *record,int n,int r)
{
	int i;

	printf("The names of the students who got the following rank are : \n")

	for(i=0;i<n;i++)
	{
		if((record+i)->rank==r)
		{
			printf("%s \n",(record+i)->rollNo);
		}
	}
}

int main()
{

	FILE *fp;
	int N,r;
	struct Student *result;

	// Idk how to take a file as input in c , maybe someone else know s

	sort(resut,N);
	rank(resut,N);

	printf("Enter the value of the rank r for the search input : ");
	scanf("%d",&r);

	search(resut,N,r);

	return 0;


}