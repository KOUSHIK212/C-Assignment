#include<stdio.h>
#include<stdlib.h>
typedef struct NodePtr
{
int v1;
struct NodePtr *l;
struct NodePtr *r;

}Node;

Node* createNode(int v1)
{
Node *node=(Node*)malloc(sizeof(Node));
node->v1=v1;
node->l = node->r=NULL;
return node;
}

Node* insert(Node *root,int v1)
{
if(root == NULL)
{
root=createNode(v1);
}
else if(v1 < root->v1)
{
root->l=insert(root->l,v1);
}
else if(v1 > root->v1)
{
root->r=insert(root->r,v1);
}
return root;

}

Node* findMinNode(Node *root)
{
if(root->l)
{
root=findMinNode(root->l);
}
return root;
}

Node* delete(Node* root,int v1)
{
if(root)
{
if(v1>root->v1)
{
root->r=delete(root->r,v1);
}
else if(v1<root->v1)
{
root->l=delete(root->l,v1);
}
else if(v1 == root->v1)
{
if(root->l && root->r)
{
Node *minNode= findMinNode(root->r);
root->v1=minNode->v1;
root->r=delete(root->r, minNode->v1);
}
else
{
Node *nodeToDelete=root;
if(root->l)
{
root=root->l;
}
else
{
root=root->r;
}
free(nodeToDelete);
}
}
}
return root;
}


void print(Node *root)
{
if(root)
{
printf("\n %d",root->v1);
print(root->l);
print(root->r);
}
}

int main()
{
Node *root=NULL;
root=insert(root,30);
root=insert(root,25);
root=insert(root,50);
root=insert(root,27);
root=insert(root,40);
root=insert(root,66);
root=insert(root,5);
root=insert(root,3);

print(root);
printf("\n \n \n");

delete(root,3);
print(root);
return 0;
}
