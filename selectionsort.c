//Sorting usiong SelectionSort Technique
//SELECTING the shortest element of the array and fixing it at first place and then apply same algorithm for the rest of the array.
// 50 20 10 40 30  
// (10) 20 50 40 30
// (10)(20) 50 40 30
// (10)(20)(30) 40 50
// (10)(20)(30)(40) 50
// (10)(20)(30)(40)(50)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int *arr;
	arr=calloc(10,4);
	int i,j,x,n,temp;
	arr=gets(arr);

	n= strlen(arr);
	
	for(i=0;i<n-1;i++)
	{
		x=i;
		for(j=i+1;j<n;j++)
		{
			if( arr[x]> arr[j])
				x=j;
		}
	temp=arr[x];
	arr[x]=arr[i];
	arr[i]=temp;
	}

	for(i=0;i<n;i++){
	printf("%d",arr[i]);
	printf("\t");
	}
}


