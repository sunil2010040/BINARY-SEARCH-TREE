#include<iostream>
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

bool identicalBST(node*root1,node*root2)
{
    if(root1==NULL &&root2==NULL)
    {
        return true;
    }
    
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    
    else
    {
        bool cond1=root1->data==root2->data;
        bool cond2=identicalBST(root1->left,root2->left);
        bool cond3=identicalBST(root1->right,root2->right);
        
        if(cond1 && cond2 &&cond3)
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
}

int main()
{
    node*root1=new node(1);
    root1->right=new node(3);
    root1->right->left=new node(2);
    root1->right->right=new node(5);
    
    
    node*root2=new node(1);
    root2->right=new node(3);
    root2->right->left=new node(2);
    root2->right->right=new node(8);
    
    if(identicalBST(root1,root2))
    {
        cout<<"BST are identical"<<endl;
    }
    
    else
    {
        cout<<"BST are not identical"<<endl;
    }
    
}