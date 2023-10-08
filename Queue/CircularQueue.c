#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

//Creat function
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(sizeof(int)*q->size);
}
//Inserting in Queue
void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size ==q->front){
        printf("Queue is Full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
//delete from Queue
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front){
        printf("Queue is Empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
//display function for queue
void Display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }
    while(i!= (q.rear+1)%q.size);
}

int main()
{
    struct Queue q;
    int k;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    Display(q);

    return 0;
}
