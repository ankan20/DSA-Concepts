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

//Recursive Insert function
Node *RInsert(Node *p,int key)
{
    Node *t=NULL;
    if(p==NULL)
    {   
        t=(Node *)malloc(sizeof(Node));
        t->data=key;
        t->rchild=t->lchild=NULL;
        return t;
    }
    if(p->data > key)
    {
        p->lchild= RInsert(p->lchild,key);
    }
    else if(p->data < key)
    {
        p->rchild= RInsert(p->rchild,key);
    }
    
    return p;
    
}
//Height of BST
int Height(Node *p)
{   
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x > y ? x+1 : y+1;
}
//Inorder Predecessor
Node *InPre(Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}
//Inorder Successor
Node *InSucc(Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}
//delete function
Node *Delete(Node *p,int key)
{   
    Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {   
        if(p==root)
            root==NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    Insert(50);
    Insert(10);
    Insert(40);
    Insert(20);
    Insert(30);
    Inorder(root);
    printf("NULL \n");
    
    Delete(root,50);
    Inorder(root);
    return 0;
}
