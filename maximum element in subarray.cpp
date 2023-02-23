#include<iostream>
using namespace std;

int max_sliding_window(int arr[],int k,int x,int n)
{
    int ans=0;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    
    if(sum<x)
    {
        ans=sum;
    }
    
    for(int i=k;i<n;i++)
    {
        sum=sum-arr[i-k];
        sum=sum+arr[i];
        
        if(sum<x)
        {
            ans=max(ans,sum);
        }
    }
    return ans;
}

int main()
{
    int arr[]={7,5,4,6,8,9};
    int k=3;
    int x=20;
    int n=6;
    cout<<"max answer in subarray:"<<max_sliding_window(arr,k,x,n);
    return 0;
}