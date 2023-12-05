#ifndef STACK_HEADER_H
#define STACK_HEADER_H

#include<stdlib.h>
#include<stdio.h>


struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st,int size)
{
    st->size = size;
    st->top =-1;
    st->S=(struct Node **)malloc(sizeof(struct Node *)*st->size);
}

void push(struct Stack *st,struct Node *x)
{
    if(st->top==st->size-1){
        printf("Stack overflow\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x=NULL;

    if(st->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        x=st->S[st->top--];

    }
}

int isEmptyStack(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    return 0;
}
int isFullStack(struct Stack st){
    return st.top==st.size-1;
}
// Stack Top element
struct Node *stackTop(struct Stack st)
{
    if (st.top == -1)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    return st.S[st.top];
}

#endif // STACK_HEADER_H
