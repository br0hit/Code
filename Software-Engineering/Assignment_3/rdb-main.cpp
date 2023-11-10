#include<iostream>

using namespace std;

void Console()
{
    int input;      // Value given by the user which will help us run the interface

    while(1)
    {
        cout<<"Enter a number: "<<endl<<endl;
        cout<<"Create new table"<<endl;
        cout<<"Delete table"<<endl;
        cout<<"Add record to table"<<endl;
        cout<<"Print table"<<endl;
        cout<<"Create table from existing tables"<<endl;
        cout<<"Press 69 to quit the program"<<endl;

        cin>>input;

        if(input==69) break;           // Special key for exiting the console

        switch (input)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    }

}


int main()
{

    // Console based user interface :
    Console();

    return 0;

}