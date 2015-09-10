#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int n, int *a) {
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(temp<a[j] && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
}

int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

insertionSort(_ar_size, _ar);
   
   return 0;
}

