#define MAXC 28

#include <stdio.h>
#include <sdltib.h>


void readMatrix ( float A[][MAXC], char *fname )
{
 FILE *fp;
 int i, j, wd=MAXC;
 fp = (FILE *)fopen(fname,"r");
 if (fp == NULL) {
 fprintf(stderr, "Error opening input file...\n");
 exit(1);
 }
 for (i=0; i<MAXC; ++i) for (j=0; j<MAXC; ++j) fscanf(fp,"%f",&A[i][j]);
 fclose(fp);
 printf("%d x %d image read from \"%s\".\n", wd, wd, fname);
}

void PrintMatrix(float inputimg[][28], int MAXC)
{
    int i,j

    for(i=0;i<MAXC;i++)
    {
        printf("Row %f:",i);

        for(j=0;j<MAXC;j++) printf("%f ",inputimg[i][j]);
    }
}

void Compress(float inputimg[][28],int MAXC)
{
    float compress[27][27] ; // Assuming the compression fileter to be an identity matrix of order 2 and the original matrix to be a 28 X 28 matrix

    int i,j;

    for(i=0;i<MAXC-1;i++)
    {
        for(j=0;j<MAXC-1;j++)
        {
            compress[i][j] = inputimg[i][j]*0 + inputimg[i][j+1]*1 + inputimg[i+1][j]*1 + inputimg[i+1][j+1]*0
        }

    }

    PrintMatrix(float compress[][27] , int 27) // the second int is MAXC- order of the compression matrix +1 which will be 27 in this case

}

void Decompress(float inputimg[][28], int MAXC)
{


}


int main()
{ 
 float inputimg[MAXC][MAXC];
 readMatrix(inputimg,"input2.csv");

 PrintMatrix(inputimg,MAXC);
 printf("\n");

 Compress(inputimg,MAXC);
 PrintMatrix(inputimg,MAXC);
 printf("\n");

 return 0; 
}