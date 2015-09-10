//Given an array of positive and negetive integers, find the max possible sum of continous elements
#include<stdio.h>
#include<stdlib.h>


int calculate(int *arr,int i, int j)
{
	int temp=0,k;
	for(k=j;k<(i+j);k++)
	{
		temp=temp+arr[k];
	}
	return temp;
}

int main()
{
	int arr[10]={1,-2,3,-4,5,-6,7,-8,9,-10};
	int sum[45];
	int i,j,x=0,max=0;
	for(i=2;i<=10;i++)
	{
		for(j=0;j<11-i;j++)
		{
			sum[x]=calculate(&arr[0],i,j);
			x++;		
		}
	}
	max=arr[0];
	for(i=0;i<45;i++)
	{
		printf("%d\t",sum[i]);
	}
	for(i=1;i<45;i++)
	{
		if(max<sum[i])
			max=sum[i];
	}
	printf("\n%d\n",max);
}

