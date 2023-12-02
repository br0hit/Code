#include<iostream>
using namespace std;

int main()
{
	cout<<"Well the for loops and do-while loops and while loops in cpp are exactly similar to that of c";

	int i;
	int a;

	cout<<endl<<"Priting consecutive integers until the one specified by the user by using all 3 loop methods";

	cout<<"Enter the integer a : "<<endl;
	cin>>a;

	for(i=0;i<a+1;i++) cout<< i;
		cout<<endl;

	i=a+1;

	while(i--) cout<< i;

	return 0;


}