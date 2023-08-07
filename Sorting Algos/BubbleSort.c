#include<stdio.h>

void BubbleSort(int A[],int n){
    int i,j;
    int flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                A[j+1]=A[j]+A[j+1];
                A[j]=A[j+1]-A[j];               //Swap for that we can write a different function also
                A[j+1]=A[j+1]-A[j];
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}



int main(){
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;
    BubbleSort(A,n);
    printf("Sorted Array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}