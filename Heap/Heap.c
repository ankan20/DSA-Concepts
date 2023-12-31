#include<stdio.h>

//Inserting element in heap
void Insert (int A[],int n)
{
    int temp,i=n; //n is last inddex
    temp = A[n];
    while( i>1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

//Create Heap
void createHeap(int A[],int n)
{
    int i;
    for(i=2 ;i<n;i++){
        Insert(A,i);
    }
}

//Delete element
int Delete(int A[], int n)
{
    int i,j,x,temp,val;
    val = A[1];
    x=A[n];
    A[1]=A[n];
    i=1;j=i*2;

    while(j<n-1)
    {
        if(A[j+1] > A[j])
            j=j+1;
        if(A[i] <A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=j*2;
        }
        else    
            break;
    }
    A[n]=val;
    return val;
}

//Print heap
void printHeap(int A[],int n)
{
    for(int i = 1;i<n;i++){
        printf("%d -> ",A[i]);
    }
    printf("\n");
}

//Heap sort
void heapSort(int A[],int n)
{
    createHeap(A,n);
    for(int i =1;i<=n-1;i++){
        Delete(A,n-i);
    }

    printHeap(A,n);
}

int main()
{
    int A[] = {0,10,20,30,25,5,40,35};
    // createHeap(A,8);
    // printHeap(A,8);
    // printf("%d \n",Delete(A,7));
    // printHeap(A,8);
    heapSort(A,8);

    return 0;
}