#include<iostream>
using namespace std;

int main()
{
	int a;

	cout<<"Enter the value of a: "<<endl;
	cin>>a;

	cout<<(float)a;

	float b;

	cout<<endl<<"Enter a floating point number : ";
	cin>>b;

	cout<<(int)b<<endl<<"Note that in typecasting the number doesnt get rounded off but gets converted to the respective type by removing everything else ";

	return 0;
}