#include<stdio.h>
#include<stdlib.h>
#include "Queue_Header.h"
struct Node *root = NULL;

void Create()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
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
        
        ineorder(p->lchild);
        printf("%d ",p->data);
        ineorder(p->rchild);
    }
}
void postorder(struct Node *p){
    if(p){
        
        postorder(p->lchild);
        
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}


int main()
{
    Create();
    preorder(root);
    return 0;
}
