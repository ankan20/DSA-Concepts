#include<iostream>
using namespace std;

class Queue
{
    private:
        int fornt;
        int rear;
        int size;
        int *Q;
    public:
        //constructor
        Queue(){
            fornt=rear=-1;
            size=10;
            Q=new int[size];
        }
        Queue(int size){
            fornt=rear=-1;
            this->size=size;
            Q=new int[this->size];
        }
        void enqueue(int x);
        int dequeue();
        void Display();
        
};
void Queue::enqueue(int x)
{
    if(rear==size-1)
    {
        cout<<"Queue is Full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue()
{   
    int x=-1;
    if(rear==fornt)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        fornt++;
        x=Q[fornt];
    }
    return x;
}
void Queue::Display()
{
    for(int i = fornt+1;i<rear+1;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main()
{   
    Queue q(5);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    q.Display();
    q.dequeue();
    q.Display();
    return 0;
}