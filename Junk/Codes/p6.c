#include <stdio.h>

void seq3(int n)
{
	printf("%d ",n); printf("1 1 1\n");
	print_seq(n); printf("1 1 1");
    printf("%d ",n); printf("1 2\n");
    print_seq(n); printf("1 2");
	printf("%d ",n); printf("2 1\n");
	print_seq(n); printf("1 2");
	printf("%d ",n); printf("3\n");
}

void seq2(int n)
{
	printf("%d ",n); printf("1 1\n");
	printf("%d ",n); printf("2\n");
}

void seq1(int n)
{ 
	printf("%d ",n); printf("1\n");
}

void print_seq(int n)
{
	int i;
    
	if(n>3) (seq3(n-3));
	if(n>2) (seq2(n-2));
	if(n>1) (seq1(n-1));

}

int main()
{
	int n=8;

	//Taking n input

// 	printf("Enter the value of n: ");
// 	scanf("%d",&n);

	print_seq(n);

	return 0;
 }