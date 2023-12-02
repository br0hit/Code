#include<stdio.h>
#include<stdbool.h>
#define CAPACITY 100  // Note that the capacity of the heap is not equal to the size 

int size;  // global variable to keep track of the number of elements in the heap
int H[CAPACITY+1];   // NOTE : Heap always start with the array of index 1 


void swap(int *a, int *b)
{
    int *temp;

    temp=a;
    a=b;
    b=temp;
}

int Root()
{
    return 1;
}

bool HasParent(int n)
{
    return n!=Root();
}
bool IsNode(int n)
{
    return n<=size;
}
int parent(int n)
{
    return n/2;
}


int LeftChild(int n)
{
    return 2*n;
}
int RightChild(int n){
    return 2*n+1;
}

void shiftUp(int H[], int n)
{
    while(HasParent(n) && (H[parent(n)]>H[n]))
    {
        swap(&H[parent(n)],&H[n]);
        n=parent(n);
    }

}

void push(int H[],int newNum)
{
    H[size+1]=newNum;
    size++;

    shiftUp(H, size);
}

void shiftDown(int H[], int n)
{
    while(IsNode(LeftChild(n)))
    {
        int child=LeftChild(n);

        if(IsNode(RightChild(n))&& RightChild(n)>LeftChild(n))
        {
             child=RightChild(n);
        }

        if(H[n]>H[child])
            swap(&H[n],&H[child]);
        else
            break;

        n=child; 
    }
}

void Pop(int H[])
{
    H[Root()]=H[size];
    size--;

    shiftDown(H,Root());
}

void buildheap(int arr[], int H[], int n)
{
    for(int i=0;i<n;i++)
    {
        H[i+1]=arr[i];
    }

    size=n;

    for(int i=size/2;i>=1;i--)
    {
        shiftDown(H,i);
    }

}

int main()
{
    int arr[] = { 51,43,93,18,42,99,54,2,74};

    int n=sizeof(arr)/sizeof(arr[0]);


    // Building the heap : 

    //  REMEMBER THAT WE ARE STARTING AT INDEX 1 FOR THE HEAP

    int H[CAPACITY+1];

    buildheap(arr,H,n);


    return 0;
}