#include<stdio.h>
#include<stdlib.h>
#include "Queue_Header.h"
#include "Stack_Header.h"
struct Node *root = NULL;

void Create()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    createQueue(&q,100);
    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter left child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
//preorder display function
void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}


//Iterative function for tree traversal
void IPreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,100);

    while(p!=NULL || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void Iinorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk,100);
    while(p!=NULL || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

// void Ipostorder(struct Node *p)
// {
//     struct Stack stk;
//     Stackcreate(&stk, 100);
//     long int temp;
    
//     while (p != NULL || !isEmptyStack(stk))
//     {
//         if (p)
//         {
//             push(&stk, (long int)p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = pop(&stk);
//             if (temp > 0)
//             {
//                 push(&stk, -temp);
//                 p = (struct Node *)(-temp)->rchild;
//             }
//             else
//             {
//                 printf("%d ", ((struct Node *)(-temp))->data);
//                 p = NULL;
//             }
//         }
//     }
// }



//LevelOrder Traversal
void Levelorder(struct Node *p)
{   
    struct Queue q;
    createQueue(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while (!isEmpty(q))
    {
        /* code */
        p=dequeue(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
    
}

int main()
{
    Create();
    printf("Preorder using recursion\n");
    preorder(root);
    printf("\nPreorder using loop\n");
    IPreorder(root);
    printf("\nInorder using recursion\n");
    inorder(root);
    printf("\nInorder using loop\n");
    Iinorder(root);
    // printf("\nPostorder using loop \n");
    // Ipostorder(root);
    printf("\nPostorder using recursion\n");
    postorder(root);
    printf("\nLevel order\n");
    Levelorder(root);
    return 0;
}
