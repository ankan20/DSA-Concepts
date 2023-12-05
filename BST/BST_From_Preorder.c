#include<stdio.h>
#include<stdlib.h>
#include "Stack_Header.h"
// BST From Preorder
struct Node *root;
void CreatePre (int Pre[],int n)
{
    struct Stack stk;
    struct Node *t,*p;
    int i=0;
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=Pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    Stackcreate(&stk, n);
    // Repeted Process for creating Bst
    while (i < n)
    {
        if(Pre[i] < p->data)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=Pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            push(&stk,p);
            p=t;
        }
        else 
        {
            if(!isEmptyStack(stk) && Pre[i] > p->data && stackTop(stk)->data >Pre[i])
            {
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=Pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else if (isEmptyStack(stk) && Pre[i] > p->data){
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=Pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else{
                p=pop(&stk);
            }
        }
    }
    
}
//Inorder function
void Inorder(struct Node *p)
{   
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ->",p->data);
        Inorder(p->rchild);
    }
    
}
int main()
{
    int arr[] = {30,20,10,15,25,40,50,45};
    CreatePre(arr,8);
    Inorder(root);
}
