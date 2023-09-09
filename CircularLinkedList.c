#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Head;
//Creating circular Linkedlist form array
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
//Display function
void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}
//Recursive display function
void RDisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag==0){
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
    
}

//Length of the LinkedList
int Lenght(){
    struct Node *p=Head;
    int count=0;
    do{
        p=p->next;
        count++;
    }while(p!=Head);
    return count;
}

//Insert function for circular LinkedList
void Insert(int index,int x){
    struct Node *p=Head;
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index<0 || index>Lenght()){
        return ;
    }
    if(index==0){
        t->next=Head;
        if(Head->next ==NULL){
            Head->next=t;
            Head=t;
        }
        else{
            while(p->next!=Head){
                p=p->next;
            }
            p->next=t;
            Head=t;
        }
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

//Delete a node from LinkeList
int Delete(int index,struct Node *p){
    int x;
    if(index<0 || index>Lenght()){
        return -1;
    }
    if(index==1){
        while(p->next!=Head){
            p=p->next;
        }
        x=Head->data;
        if(p==Head){
            free(Head);
            Head=NULL;
        }
        else{
            p->next=Head->next;
            
            free(Head);
            Head=p->next;
        }
        
    }
    else{
        struct Node *q;
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
        
    }
    return x;
}

int main()
{

    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    RDisplay(Head);
    printf("\n");
    Insert(1,11);
    Display(Head);
    int b=Delete(3,Head);
    Display(Head);
    return 0;
}
