#include<iostream>
using namespace std;

struct node
{
    int data;
    node*left,*right;
    
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

node*insertBST(node*root,int value)
{
    if(root==NULL)
    {
        return new node(value);
    }
    
    if(value < root->data)
    {
        root->left=insertBST(root->left,value);
    }
    
    else
    {
        root->right=insertBST(root->right,value);
    }
    
    return root;
}

int main()
{
    node*root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,7);
    
}