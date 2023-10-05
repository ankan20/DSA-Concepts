#include<stdio.h>
//Tail Recursion
void fun(int n){
    if(n>0){
        printf("%d ",n);
        fun(n-1);
    }
}
//Head Recursion
void fun1(int n){
    if(n>0){
        fun1(n-1);
        printf("%d ",n);
    }
}

int main(){
    int x=3;
    fun1(x);
    return 0;
}