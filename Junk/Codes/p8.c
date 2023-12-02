#include<stdio.h>

void MUL(char a[],char b[],char c[])
{

}

void Add(char a[],char b[],char[c])
{
	int i,j,max,check=0,temp=0;  // check used to decide which number of the 2 is greater
   char carry;

   // Finding out the number with more digits among the two of them

   for(i=0;a[i]!='\0';i++);
   	max=i;  		  // Assuming it to be i
   for(i=0;b[i]!='\0';i++);
   	if(i>max) { max=b; check=1 }  // Finding out the max 

   if(check==0)
   {
   	for(i=0;b[i]!='\0';i++)
   	{

   		temp=a[i]+b[i]+carry-96;
   		if(temp>9) { carry=1; temp=temp-9; }
   		else {carry=0; temp=temp-9}

   		c[i]=temp+48;
   	}
   	for(j=i;j<max;j++)
   	{
   		c[i]=carry+
   	}
   }
}

int main()
{
	char a[100],b[100],c[100];

	prntf("Enter numbers a and b : ");
	scanf("%s%s",&a,&b);

	// Finding out c by calling the recursive function

	c=MUL(a,b,c);

	printf("The product of %s and %s is\n%s",a,b,c);
}