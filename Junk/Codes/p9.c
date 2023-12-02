// #include<stdio.h>

typedef struct
{
	long long int day;
	long long int month;
	long long int year;	
}Date;

Date readDate(void)
{
	Date x;

	long long int date;

	printf("\nEnter the date in the format of dd/mm/yyyy : ");
	scanf("%lld",&date);

	x.year=date%10000;
	x.day=date/1000000;
	x.month= date/10000-(100*x.day);

	return x;
}

// void printDate(Date x)
// {
// 	printf("\nThe date entered by the user in the format of dd/mm/yyyy is\n %d / %d / %lld",x.day,x.month,x.year);
// }

long long int Totaldays(Date x)
{

	// We will calucalte the total number of days between the two given days by the following method

	// First calucalte the total number of days from 00/00/0000 from x and y and the subract them

// converting the months present into days  

	// Ifthe month is 02 we have to add the days of jan and if 03 then jan and feb and so on...

	if(x.month==2) x.month=31;  // For jan

	// For Feb it will depend 29 or 28 based on its a leap year or not
	else if(x.month==3 && x.year%4==0) x.month=31+29;
	else if(x.month==3) x.month=31+28;

	// Since the remaining months have either 30/31 days alternatively we can write a single code
	else
	{
		if(x.year%4==0)  	// For Feb it will depend 29 or 28 based on its a leap year or not
		{
			if(x.month%2==0) x.month=31+29+(x.month/2)*31+((x.month/2)-1)*30;
			else x.month=31+29+((x.month/2)-1)*(31+30);
		}
		else
		{
			if(x.month%2==0) x.month=31+28+(x.month/2)*31;
			else x.month=31+28+((x.month/2)-1)*(31+30);
		}
	}

	// Now x.month holds the no. of days till that month

// Converting the year into days

	x.year=x.year-1; // First converting .year into the number of years completed

		 printf("\n\n%lld%lld\n\n", x.year,x.year/4); //Check

  // To convert year into days first do *366 for leap years and *355 for the remaining

	x.year= ((x.year/4)*366 + ((x.year-(x.year/4))*365));

	// Now x.year will hold the no. of days till that particualar year

	// Caluclating the totla no. of days :

	 printf("\n\n%lld\n\n", x.year); //Check

	return x.day+ x.month+ x.year;
}

long long int dayCount(Date d1, Date d2)
{
	if((Totaldays(d1)-Totaldays(d2))>0) return (Totaldays(d1)-Totaldays(d2));
	return (Totaldays(d2)-Totaldays(d1)) ; // Making sure the no. of dates bw the two dates is +ve
}

int main()
{
	Date x,first_date,second_date;

	// x=readDate(); // Reading the date from the user

	// printDate(x);  // Printing the date entered

	printf("\n\nCalucalting the number of days bw the 2 dates: \n\n");

	printf("Enter the first date:");
	 first_date=readDate();
	printf("Enter the second date:");
	second_date=readDate();

	printf("\n The number of days between the two given dates is : %lld",dayCount(first_date,second_date));

	return 0;


}