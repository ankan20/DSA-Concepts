#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;         //size of array or size of queue
    int rear;
    int front;
    int *Q;          //pointer to a array 
};

//Create function
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}
//function for insert
void enqueue(struct Queue*q,int x)
{   //condition for isFull
    if(q->rear==q->size-1){
        printf("Queue is Full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
//function for delete a element
int dequeue(struct Queue *q){
    int x=-1;
    //condition for isEmpty
    if(q->rear==q->front){
        printf("Queue is Empty");
    }
    else{
        q->front++;
        x=q->Q[q->front];
        
    }
    return x;
}
//display function
void Display(struct Queue q)
{
    int i;
    for(i=q.front+1;i<q.rear+1;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    int sz;
    printf("Enter the size of queue ");
    scanf("%d",&sz);
    create(&q,sz);
    enqueue(&q,10);
    enqueue(&q,1);
    enqueue(&q,101);
    enqueue(&q,103);
    Display(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,200);
    Display(q);
    


    return 0;
}