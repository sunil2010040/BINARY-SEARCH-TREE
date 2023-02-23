#include<iostream>
using namespace std;

int smallest_subarray(int arr[],int n,int x)
{
    int sum=0,minL=n+1,start=0,end=0;
    while(end<n)
    {
        while(sum<=x && end<n)
        {
            sum+=arr[end++];
        }
        
        while(sum>x && start<n)
        {
            if(end-start<minL)
            {
                minL=end-start;
            }
            sum-=arr[start]++;
        }
    }
    return minL;
}

int main()
{
    int arr[]={1,4,45,6,10,19};
    int x=51,n=6;
    
    int minL=smallest_subarray(arr,n,x);
    if(minL==n+1)
    {
        cout<<"no such subsrray exist"<<endl;
    }
    
    else
    {
        cout<<"minimum length of subarray:"<<minL<<endl;
    }
    
}