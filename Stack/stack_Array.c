#include<stdio.h>
#include<stdlib.h>

//Structure for a stack
struct Stack 
{
    int size;
    int top;
    int *S;
};
//creating a stack 
void create(struct Stack *st)
{
    printf("Enter the size of stack : ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(sizeof(int)*st->size);
}
//display fucntion for stack 
void Display (struct Stack st)
{   
    int i;
    for(i=st.top ;i>=0;i--){
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

//Push a new element to stack
void Push(struct Stack *st,int x)
{   
    if(st->top == st->size-1){
        printf("Stack is full or Stack overflow\n");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }   
}
//Delete a element from stack
int Pop(struct Stack *st)
{   
    int x=-1;
    if(st->top == -1){
        printf("Stack is empty or StackUnderflow\n");
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}
//return value at given index
int Peek(struct Stack st ,int index)
{   
    int elem =-1;
    int pos;
    if(index > st.size-1 || index < 0){
        printf("Invalid index\n");
    }
    else {
        pos = st.top - index +1;
        elem = st.S[pos];
    }
    return elem;
}

//Empty or not
int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else 
        return 0;
}
//Full or not
int isFull (struct Stack st)
{
    if(st.top == st.size -1)
        return 1;
    else 
        return 0;
}
//stack top element
int stackTop(struct Stack st)
{
    if(st.top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    else {
        return st.S[st.top];
    }
}
int main()
{
    struct Stack st;
    create(&st);
    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    Display(st);
    printf("%d\n",Pop(&st));
    Display(st);
    printf("%d \n",Peek(st,3));
    printf("%d ",stackTop(st));
    return 0;
}