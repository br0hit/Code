#include<iostream>
using namespace std;

int main()
{
	cout<<"For taking input from user we use cin instead of cout"<<endl<<"Note that in this case we have to use greater than symbol contarary to the less than symbol used in cout so"<<endl<<"cout<< cin>>";

	cout<<endl<<"Now to take input first declare the variable and then use cin to take input"<<endl;

	int a,b;

	cout<<"Enter the first number: ";
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;

	cout<<"THe difference between the two numbers is : "<<a-b;

	cout<<endl<<"THe division rule over here is similar to that of C so inter/integer will result in an integer";

	cout<<endl<<"division of the 2 numbers will result in :"<<a/b;
	cout<<endl<<"When we divide an integer by a floating point variable :"<<a/2.0;

	return 0;
}

