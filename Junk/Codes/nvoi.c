#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
 
int FindIt (int* arr, int n) {
   // Write your code here

   int i;
   int min=99999;

   for(i=0;i<n;i++)
   {
      if(arr[i]<min)
      {
         min=arr[i];
      }


return min;
   
}
 
int main() 
{
    int n;
    scanf("%d", &n);
    int i_arr;
    int *arr = (int *)malloc(sizeof(int)*(n));
    for(i_arr = 0; i_arr < n; i_arr++)
    	scanf("%d", &arr[i_arr]);
 
    int out_;
    out_ = FindIt(arr,n);
    printf("%d", out_);
}