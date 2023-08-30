#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

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

//Creating 2nd Linked List

void create2(int A[],int n){

    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

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

//Inserting a element in a sorted LL
void SortedInsert(struct Node *p,int data){
    
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
   
   else{
    while(p && p->data<data){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
        t->next=q->next;
        q->next=t;
    }
   }
}

//Deleting a element at given position
int DeleteNode(struct Node *p,int index){

    struct Node *q;
    int x=-1,i;
    //checking if index is valid or not
    if(index < 1 || index > Count(p)){
        return -1;
    }

    //If index is 1st 
    if(index == 1){
       q=first;
       x=first->data;
       first=first->next;
       free (q);
       return x;
        
    }
    else {
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;

        }
        q->next=p->next;
        x=p->data;
        free (p);
        return x;
    }
}

//Check if LinkedList is sorted or not
int CheckSorted (struct Node *p){
    int x = INT32_MIN;
    while(p!=NULL){

        if(p->data < x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

//Delete duplicate elements from SORTED LinkedList
void RemoveDuplicate(struct Node *p){
    struct Node *q;
    q=p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

//Reversing a LinkedList using array ,reverse the data
void Reverse1(struct Node *p){
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*Count(p));
    while(q!=NULL){

        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

//Reverse a LinkedList using 3 pointer ,reverse the Links
void Reverse2(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}

//Recursive function for reversing a LinkeList
void Reverse3(struct Node *q,struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }

}

//Concat two sorted LinkedList
void Concat(struct Node *p,struct Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;

}

//Merging two SORTED LinkedList
void Merge(struct Node *p,struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p){
        last->next=p;
    }
    if(q){
        last->next=q;
    }
}



int main()
{   
    struct Node *temp;
     int A[]={10,20,30,40,50};
     int B[]={5,15,25,35,45};


    create(A,5);
    create2(B,5);
    printf("\nFirst\n");
    display(first);
    printf("\n");
    printf("\nSecond\n");
    display(second);
    printf("\n");
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
    
    // InsertionInpos(first,30,0);
    // display(first);
    // SortedInsert(first,12);
    // display(first);
    // printf("\n");
    // SortedInsert(first,1);
    //  display(first);
    // printf("\n");
    // SortedInsert(first,200);
    // display(first);
    // printf("\n");

    // printf("Deleted element is %d\n",DeleteNode(first,4));
    // display(first);
    // printf("Checking LinkedList is sorted or not %d\n",CheckSorted(first));
    // RemoveDuplicate(first);
    // display(first);

    // Reverse3(NULL,first);
    // display(first);
    // Concat(first,second);
    // display(third);
    Merge(first,second);
    display(third);


    return 0;
}
