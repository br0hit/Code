#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{

    int i=0,j=0,flag=0,set1[20];


    for (i = 0; i<20; i++)
{
    flag=0;
    srand(time(0));

    if(i==0) set1[i]=rand()%41 +10;

    else 
    {
        while(1)
    {
       set1[i]=rand()%41 +10;
       for(j=0;j<i;j++)
       {
         if(set1[j]==set1[i])
         {
            flag=1; break;
         }
       }

       if(flag==0) break;      
    }

     if(flag==0) break;

    }

    
}

for(i=0;i<20;i++) printf(" %d",set1[i]);

}

