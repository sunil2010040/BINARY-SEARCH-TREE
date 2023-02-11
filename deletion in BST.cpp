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

node*inordersucc(node*root)
{
    node*curr=root;
    while(curr &&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

node*deleteBST(node*root,int key)
{
    if(key<root->data)
    {
        root->left=deleteBST(root->left,key);
    }
    
    else if(key>root->data)
    {
        root->right=deleteBST(root->right,key);
    }
    
    else
    {
        if(root->left==NULL)
        {
            node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node*temp=root->left;
            free(root);
            return temp;
        }
        
        node*temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
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
    
    root=deleteBST(root,5);
    inorder(root);
}