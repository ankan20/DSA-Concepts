#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;
Node *root=NULL;

//Insert function for BST
void Insert(int key)
{
    Node *t=root;
    Node *r,*p;
    if(root==NULL)
    {
        p=(Node *)malloc(sizeof(Node));
        p->data=key;
        p->rchild=p->lchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key < t->data)
        {
            t=t->lchild;
        }
        else if(key > t->data)
        {
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p=(Node *)malloc(sizeof(Node));
    p->data=key;
    p->rchild=p->lchild=NULL;
    if(r->data > key)
    {
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}
//Search in BST
Node * Search(int key)
{
    Node *t=root;
    while(t!=NULL)
    {
        if(key > t->data)
        {
            t=t->rchild;
        }
        else if (key < t->data)
        {
            t=t->lchild;
        }
        else {
            return t;
        }
    }
    return t;
}

//Inorder function
void Inorder(Node *p)
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
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    printf("NULL \n");
    printf("%d ",Search(200));
    return 0;
}