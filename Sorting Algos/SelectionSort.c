#include<stdio.h>

void swap(int *n,int *m){
    int temp;
    temp=*n;
    *n=*m;
    *m=temp;
}

void SelectionSort(int A[],int n){
    int i,j,k;

    for(i=0;i<n-1;i++){
        for(k=j=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}



int main(){
    int A[]={1,7,8,0,2,5,3,4,9,6},n=10,i;

    SelectionSort(A,n);
    printf("Sorted array is :\n");

    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
