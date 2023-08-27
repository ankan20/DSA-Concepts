#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){

    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}

//counting total number of node
int Count(struct Node *p){
    int c=0;
    while(p!=NULL){       //we can also write as while(p)---->itwill false when p=0 or p=NULL and true otherwise
        p=p->next;
        c++;
    }
    return c;
}

//Recursive function for counting node

int Rcount(struct Node *p){
    if(p==NULL){
        return 0;
    }
    return Rcount(p->next) + 1;
}

//function for sum of all element in LL
int Sum(struct Node *p){
    int s=0;
    while(p){
        s+=p->data;
        p=p->next;
    }
    return s;
}
//Recursive function for sum
int Rsum(struct Node *p){
    if(p!=NULL){
        return Rsum(p->next) + p->data;
    }
    else 
        return 0;
}

//Maximum element in LL
int Max(struct Node *p){
    int max=INT32_MIN;
    while(p){
        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

//Maximum element in LL recursive
int RMax(struct Node *p){
    int x=0;
    int max=INT32_MIN;
    if(p==NULL){
        return max;
    }
    x=Max(p->next);
    if(x>p->data){
        return x;
    } 
    else 
        return p->data;
}

//Searching -->Linear search on LL
struct Node *search(struct Node *p,int key){
    struct Node *q=NULL;
    while(p!=NULL){
        if (key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

//Recursive function for linear search
struct Node *Rsearch(struct Node *p,int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return Rsearch(p->next,key);
}

//Insertion in LL
void InsertionInpos(struct Node *p,int data,int pos){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    if(pos <0 || pos >Count(p)){
        return;
    }
    else if(pos==0){
        t->next=first;
        first=t;
    }
    else if(pos>0){
        struct Node *temp;
        temp=p;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;
    }
}

int main()
{   
    struct Node *temp;
    int A[]={3,5,7,10,15,7,6,10,100};

    create(A,9);
    //display(first);
    //Rdisplay(first);
    //printf("Total number of node is %d",Rcount(first));
    //printf("Sum of the elements is %d ",Rsum(first));
    //printf("Maximum element in the LinkedList is %d ",Max(first));
    // temp=search(first,10);
    // if(temp)
    //     printf("Key is Found %d\n",temp->data);
    // else
    //     printf("Key is not Found");
    display(first);
    printf("\n");
    InsertionInpos(first,30,0);
    display(first);

    return 0;
}
