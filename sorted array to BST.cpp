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

node*bal_BST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    node*root=new node(arr[mid]);
    
    root->left=bal_BST(arr,start,mid-1);
    root->right=bal_BST(arr,mid+1,end);
    
    return root;
}

void preorder(node*root)
{
    if(root==NULL)
    {
        return; 
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[]={10,20,30,40,50,60,70,80,90};
    node*root=bal_BST(arr,0,8);
    preorder(root);
}