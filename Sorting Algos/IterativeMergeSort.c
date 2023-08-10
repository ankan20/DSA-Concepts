#include<stdio.h>

void Merge(int A[],int l,int mid,int h){

    int i,j,k;
    i=l;j=mid+1;k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[i];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IMergeSort(int A[],int n)
{
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i+=p)
        {
            l=i;
            h=i+p-1;
            mid=(i+h)/2;
            Merge(A,l,mid,h);

        }
    }
    if(p/2<n)
        Merge(A,0,p/2 -1,n-1);
}

int main(){
    int A[]={11,13,7,2,6,9,4,5,10,3},n=10,i;

    printf("Sorted Array is \n");
    
    IMergeSort(A,n);
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}
