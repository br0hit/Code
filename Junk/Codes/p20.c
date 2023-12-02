#include <stdio.h>
#include<stdlib.h> // contains malloc

int main()
{
	int *p ;
	int q[5]; // 6*sizeof(int)
	int **q;  // stores the element sin the first row
	// int ***r;
	int x;

	int A[1000] // A[n] X

	p=&x;
	x=5;
	x++;

	*p;


	

	p = (int *)malloc(4*sizeof(int));  //malloc

	// P= 1024-1027 ; 1028- 1031 ;1032-1035; 1036-1039; p 1024 , p+1 1028 , AND NOT 1025 ( p+1(sizeof(int))), p+2 1032 p+2()

	*p = x;

	*(p+1/* size of that respective pointer */ ) =
	*(p+2) //integer which is tored in the position 1032
	*(p+3)

	// A[10], A[0],A[1],A[2].....A[10]   // We already defined  a pointer named *A and also allocated a space n  which is in the A[n]
	// *p,    *p, *(p+1), *(p+2)....
	//  *p ,   p[0],p[1],p[2],p[3].....

	p=(int *) malloc(5*sizeof(int));  // array of size 5 p[0]/ *p and p[1] or *(p+1) p[5] // Segmentation error


int a;
	scanf("%d",&a);

	char c[20];
	scanf("%s",c);

	char *p;
	scanf("%s",p);









	int p=5;

	p=(float)p/3;  //Typedef
}