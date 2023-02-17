#include<iostream>
using namespace std;

int catalon(int n)
{
    if(n<=1)
    {
        return 1;
    }
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=catalon(i)*catalon(n-i-1);
    }
    
    return ans;
}

int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cout<<catalon(i)<<" ";
    }
}