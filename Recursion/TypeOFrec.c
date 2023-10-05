#include<stdio.h>

//Indirect Recursion --->Call himself by a different funtion which function it calls
void funA(int n);
void funB(int n);
void funA(int n){
    if(n>0){
        printf("%d ",n);
        funB(n-1);
    }
}

void funB(int n){
    if(n>0){
        printf("%d ",n);
        funA(n/2);
    }
}

//Nested recursion -->after doing tast call himself by passing himself by modified value
int fun(int n){
    if(n>100){
        return n-10;
    }
    
    return fun(fun(n+11));

}

int main(){
    int r;
    // funA(20);
    r=fun(95);
    printf("%d ",r);
    return 0;
}