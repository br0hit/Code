#include<stdio.h>
#include<stdlib.h>

// printf("check");

// void merge(int arr[], int start, int mid, int end)
// {
// 	int array[100];

// 	int i;

// 	// int left[100],right[100];

// 	// for(i=start;i<mid;i++) left[start]=arr[start]

// 	for(i=start;i<end+1;i++) array[i]=arr[i];

// 	int index_left,index_right,main_index;

// 	index_left=start;
// 	index_right=mid+1;
// 	main_index=start;


// 	while(main_index<end+1)
// 	{
// 		if(array[index_left]>array[index_right])
// 		{
// 			arr[main_index]=array[index_right];

// 			index_right++;
// 			main_index++;
// 		}

// 		else
// 		{
// 			arr[main_index]=array[index_left];

// 			index_left++;
// 			main_index++;
// 		}
	
// }
// // 	if(index_left==mid)
// // 	{
// // 		for(i=index_right;i<end;i++,main_index++) arr[main_index]=array[i];
// // 	}

// // else
// // {
// // 	for(i=index_left;i<mid;i++,main_index++) arr[main_index]=array[i];
// // }


// }

void merge(int arr[], int start ,int mid, int end)
{
	int p,q;

	p= mid-start+1;
	q=end-mid;

	int P[p],Q[q];

	int i,j;

	for(i=0;i<p;i++) P[i]=arr[start+i];
	for(i=0;i<q;i++) Q[i]=arr[mid+1+i];

	int k,total;

	i=0;j=0;
	k=start;


	total=end-start+1;

	// for(k=start,i=0,j=0;k<total;k++)
	// {
	// 	if(P[i]>Q[i])
	// 	{
	// 		arr[k]=Q[j];
	// 		k++;
	// 		j++;
	// 	}

	// 	else
	// 	{
	// 		arr[k]=P[i];
	// 		k++;
	// 		j++;
	// 	}
	// }

	while(i<p &&j<q)
	{
		if(P[i]>Q[j])
		{
			arr[k]=Q[j];
			k++;
			j++;
		}

		else
		{
			arr[k]=P[i];
			k++;
			i++;
		}

	}

	while(i<p)
	{
		arr[k]=P[i];
		k++;i++;
	}

	while(j<q)
	{
		arr[k]=Q[j];
		k++;j++;
	}

}



void merge_sort(int arr[],int start, int end)
{
	// if(start==end) return;

	// 	int mid;

	// 	mid= start+end/2;

			// printf("check");

	// merge_sort( arr,  start,  mid );
	// 	merge_sort( arr,  mid+1,  end );

	// 	merge( arr, start, mid, end);

	if(start<end)
	{

		int mid;

		mid=start+end/2;

		merge_sort( arr,  start,  mid );
		merge_sort( arr,  mid+1,  end );

		merge( arr, start, mid, end);


	}




}



int main()
{
	int arr[o]={5,2,8,1,10,3,7,9,4,6};

	merge_sort(arr,0,9);

	int i;

	for(i=0;i<10;i++) printf("%d",arr[i]);

		return 0;

}