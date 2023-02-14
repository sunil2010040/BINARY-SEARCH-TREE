#include<iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    node*left,*right;
    
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

node*constructBST(int preorder[],int *preorderidx,int key,int min,int max,int n)
{
    node*root=NULL;
    if(*preorderidx>=n)
    {
        return NULL;
    }
    
    if(key>min && key<max)
    {
        root=new node(key);
        *preorderidx=*preorderidx+1;
        
        if(*preorderidx<n)
        {
            root->left=constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        
        if(*preorderidx<n)
        {
            root->right=constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    
    return root;
}

void printpreorder(node*root)
{
    if(root==NULL)
    {
        return; 
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}

int main()
{
    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderidx=0;
    node*root=constructBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX ,n);
    printpreorder(root);
    
    return 0;
    
}