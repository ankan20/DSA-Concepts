#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void creatNode(int A[],int n ){
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

//Display function
void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//Lenght counting function
int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

//Insert function
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;

    if(index<0 || index>Length(p)){
        return ;
    }
   if(index==0){
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=first;
    first->prev=t;
    t->prev=NULL;
    first=t;
   }
   else{
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    for(i=0;i<index-1;i++){
        p=p->next;
    }
    t->next=p->next;
    t->prev=p;
    if(p->next){
        p->next->prev=t;
    }
    p->next=t;
   }
}



int main(){

    int A[]={10,20,30,40,50};
    creatNode(A,5);
    printf("\nLength is :%d\n",Length(first));
    Display(first);
    Insert(first,0,100);
    Display(first);

    return 0;
}
