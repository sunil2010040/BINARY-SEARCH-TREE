#include<iostream>
#include<stack>
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

void zigzag_traversal(node*root)
{
    if(root==NULL)
    {
        return;
    }
    
    stack<node*>curr;
    stack<node*>next;
    
    bool lefttoright=true;
    
    curr.push(root);
    
    while(!curr.empty())
    {
        node*temp=curr.top();
        curr.pop();
        
        if(temp)
        {
            cout<<temp->data<<" ";
        }
        
        if(lefttoright)
        {
            if(temp->left)
            {
                next.push(temp->left);
            }
            if(temp->right)
            {
                next.push(temp->right);
            }
        }
        
        else
        {
            if(temp->right)
            {
                next.push(temp->right);
            }
            
            if(temp->left)
            {
                next.push(temp->left);
            }
        }
        if(curr.empty())
        {
            lefttoright=!lefttoright;
            swap(curr,next);
        }
    }
}
int main()
{
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    root->left->right=new node(6);
    root->left->right->right=new node(7);
    
    zigzag_traversal(root);
    return 0;
}
