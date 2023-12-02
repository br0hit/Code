#include <stdio.h>
#include<stdlib.h>

void printArr (int plainData[],int n)
{
	int i;

	for(i=0;i<n;i++) printf("%d ",plainData[i]);
}



void random_fill(int plainData[]){
    
    int seed;
    int  n=25;
    printf("Enter seed: ");
    scanf("%d",&seed);
    srand(seed);
    int i;
    for(i=0;i<n;i++){
        plainData[i]=rand()%16+10;
    }
    printf("The formed array is: [");
    printArr(plainData,n);
    printf("]");
}


void encode (int plainData[])
{
    int cypherData[10];
    int i;

    for(i=0;i<23;i+=3)
    {
        if(i<23) { cypherData[i/3]=plainData[i]+plainData[i+1]+plainData[i+2]; }
        if(i==24) cypherData[i/3] = plainData[i-1];
    }

    printf("\n\nThe encoded Array is [");
    printArr(cypherData,9);
    printf("]");

}


int main()
{
    int plainData[25];
    random_fill(plainData);
    encode(plainData);   
}


