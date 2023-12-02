// #include<stdio.h>	

typedef struct
{
	int day;
	int month;
	int year;	
}Date;

Date Difference(Date d1,Date d2)
{

	// Assuming d1 occurs eearlier than d2 :

	Date d3; // d3 is the difference between the two dates
	int sum_month_and_days

	// Finding the year difference

	d3.year=(Totaldays(d1)-Totaldays(d2))/365;

	// Finding the month difference

	//Before we divide by 30 ; we need to remove the 1 day for every leap year

	sum_month_and_days= ((Totaldays(d1)-Totaldays(d2))%365) - (d2.year-d1.year)/4;

	d3.month = sum_month_and_days/30;

	// Finding the day difference

	d3.day= sum_month_and_days%30;

	return d3;

}

 int Totaldays(Date x)
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

  // To convert year into days first do *366 for leap years and *355 for the remaining

	x.year= ((x.year/4)*366 + ((x.year-(x.year/4))*365));

	// Now x.year will hold the no. of days till that particualar year

	// Caluclating the totla no. of days :

	return x.day+ x.month+ x.year;
}




// int main()
// {

// }