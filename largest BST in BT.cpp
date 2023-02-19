#include<iostream>
#include<climits>
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

struct info
{
    int min;
    int max;
    int size;
    int ans;
    bool BST;
};

info largest_BSTin_BT(node*root)
{
    if(root==NULL)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    
    if(root->left==NULL && root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    
    info leftinfo=largest_BSTin_BT(root->left);
    info rightinfo=largest_BSTin_BT(root->right);
    
    info curr;
    curr.size=(1+leftinfo.size+rightinfo.size);
    
    if(leftinfo.BST && rightinfo.BST && leftinfo.max<root->data &&rightinfo.min>root->data)
    {
        curr.min=min(leftinfo.min,min(rightinfo.min,root->data));
        curr.max=max(rightinfo.max,max(leftinfo.max,root->data));
        
        curr.ans=curr.size;
        curr.BST=true;
        
        return curr;
    }
    
    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.BST=false;
    return curr;
}

int main()
{
    node*root=new node(15);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(5);
    
    cout<<"largest BST in BT: "<<largest_BSTin_BT(root).ans<<endl
    return 0;
}
    
    
    
    
