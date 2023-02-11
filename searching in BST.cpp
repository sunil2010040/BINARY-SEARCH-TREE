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

node*search(node*root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data==key)
    {
        return root;
    }
    
    if(key<root->data)
    {
        return search(root->left,key);
    }
    
    else
    {
        return search(root->right,key);
    }
}

node*insertBST(node*root,int value)
{
    if(root==NULL)
    {
        return new node(value);
    }
    
    if(value<root->data)
    {
        root->left=insertBST(root->left,value);
    }
    
    else
    {
        root->right=insertBST(root->right,value);
    }
    
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node*root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    
    inorder(root);
    cout<<endl;
    
    int key=7;
    
    if(search(root,key)!=NULL)
    {
        cout<<"key exist"<<endl;
    }
    
    else
    cout<<"key doesn't exist"<<endl;
    return 0;
}