#include<stdio.h>	

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

	// Finding the year difference

	d3.year= d2.year-d1.year;
	if((d2.month-d1.month<0) || ((d2.month==d1.month) && (d2.day<d1.day)) ) d3.year--;

	// Finding month difference

	d3.month=d2.month-d1.month;


	// Day difference

	while()




}



int main()
{

}