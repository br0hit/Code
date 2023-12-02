typedef struct student
{
	char name[19];
	float marks[5];
	char roll_no[20];
}student;

#include <stdio.h>
#include <string.h>

void readlist( student list[],int size)	
{
	int i,j;
	for(i=0;i<size;i++)
	{
		printf("Details of Student no.%d\n",i+1);
		//Name

		printf("Name of student: ");
		scanf("%s",list[i].name);

		//Marks

		for(j=0;j<5;j++)
		{
			printf("Marks in subject %d : ",j+1);
			scanf("%f",&list[i].marks[j]);
		}

		//Roll No.

		printf("Roll no. :");
		scanf("%s",list[i].roll_no);

	}

}

void printlist( student list[],int size)
{
	int i,j;

	for(i=0;i<size;i++)
	{
		printf("Details of Student no.%d given by the user: \n",i+1);
		printf("%s\n",list[i].name);
		for(j=0;j<5;j++) printf("Marks in subject no.%d : %f\n",j+1,list[i].marks[j]);
		printf("%s\n",list[i].roll_no);
	}

}

void sortlist( student list[],int size,int code)
{
     student temp;
    int i,j;
    if(code==1)
    {
        for(i=0;i<size;i++)
            {
                for(j=i+1;j<size;j++)
                    {
                        if(strcmp(list[i].name,list[j].name)>0)
                            {
                                temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                    }
            }
    }
    if(code==2)
    {
        for(i=0;i<size;i++)
            {
                for(j=i+1;j<size;j++)
                    {
                        if(strcmp(list[i].roll_no,list[j].roll_no)>0)
                            {
                                temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                    }
            }
    }
    if(code==3)
    {
        for(i=0;i<size;i++)
            {
                for(j=i+1;j<size;j++)
                    {
                        if((list[i].marks[0]+list[i].marks[1]+list[i].marks[2]+list[i].marks[3]+list[i].marks[4])>(list[j].marks[0]+list[j].marks[1]+list[j].marks[2]+list[j].marks[3]+list[j].marks[4]))
                            {
                                temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                    }
            }
    }
}


int main()
{
	 student list[10];
	int size,code;

	printf("Enter the number of students present: ");
	scanf("%d",&size);

	// Reading the data of 'size' no. of students

	readlist(list,size);

	//Printing the students data

	printlist(list,size);

	//Sorting

	printf("Enter the code for the type of sort : ");
	scanf("%d",&code);

	sortlist(list,size,code); // Sorting based on code

	printlist(list,size);  // Printing the modified list after the sort


}

