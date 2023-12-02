// NAME : R.SASHANK RATHOD
//ROLL NO : 21IM30028
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void findmax(int a[][20],int x,int y)
{
    //max variable is updated each time a new value for max sum is found ,and index stores the starting index values of the max sub-matrix.
    int i,j,k,l,max=0,index[2];
    // in the following code ,the first 2 for loops is for accessing each element and the successive 2 loops will look in the 3x3 matrix starting from the accessed element.
    for(i=0;i<=x-3;i++)
    {
        for(j=0;j<=y-3;j++)
            {
            int sum=0;
            for(k=0;k<3;k++)
                {
                for(l=0;l<3;l++)
                {
                    sum=sum+a[i+k][j+l];
                }
            }
            // if a new higher value of sum is found , max variable is updated and the index is stored.
            if(sum>max)
            {
                max=sum;
                index[0]=i;
                index[1]=j;
            }
        }
    }
    // printing the sub-matrix.
    printf("\nThe max sub-matrix is\n");
    for(k=index[0];k<3+index[0];k++)
        {
        for(l=index[1];l<3+index[1];l++)
        {
            printf("%2d  ",a[k][l]);
        }
        printf("\n");
    }
    printf("Sum = %d",max);
}
void findmin(int a[][20],int x,int y)
{
    //min variable is updated each time a new value for max sum is found ,and index stores the starting index values of the max submatrix.
    int i,j,k,l,min=10*x*y,index[2];
    // in the following code ,the first 2 for loops is for accessing each element and the successive 2 loops will look in the 3x3 matrix starting from the accessed element.
    for(i=0;i<=x-3;i++){
        for(j=0;j<=y-3;j++){
            int sum=0;
            for(k=0;k<3;k++){
                for(l=0;l<3;l++){
                    sum+=a[i+k][j+l];
                }
            }
            // if a new min value of sum is found , min is updated and the index value is stored .
            if(sum<min){
                min=sum;
                index[0]=i;
                index[1]=j;
            }
        }
    }
    // printing the min sub-matrix.
    printf("\nThe min sub-matrix is\n");
    for(k=index[0];k<3+index[0];k++)
        {
        for(l=index[1];l<3+index[1];l++)
        {
            printf("%2d  ",a[k][l]);
        }
        printf("\n");
    }
    printf("Min = %d",min);
}
int main()
{
    srand(time(0));                     //setting seed for generating random values.
    int m,n,i,j,a[20][20];
    printf("Enter number of rows (between 2 and 20 ): ");
    scanf("%d",&m);
    if ((m>2)&&(m<20))                  //checks if row number is within range
    {
        printf("Enter number of columns (between 2 and 20 ): ");
        scanf("%d",&n);
        if ((n>2)&&(n<20))              // checks if column number is within range
        {
            for(i=0;i<m;i++)
                {
                for(j=0;j<n;j++)
                {                       //assigning random values into the matrix
                    a[i][j]=rand()%10;
                }
            }
            printf("\nThe matrix is :\n");
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {                       //printing the matrix
                    printf("%2d  ",a[i][j]);
                }
                printf("\n");
            }
            findmax(a,m,n);         // finding the max submatrix
            findmin(a,m,n);         // finding the min submatrix

        }else 
           printf("invalid input");
    }
    else 
          printf("invalid input");
    return 0;

}