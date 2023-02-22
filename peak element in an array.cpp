#include<iostream>
using namespace std;

int peak_element(int arr[],int low,int high,int n)
{
    int mid=low+(high-low)/2;
    
    if((mid==0||arr[mid]>=arr[mid-1]) && ( mid==n-1 || arr[mid]>=arr[mid+1]))
    {
        return mid;
    }
    
    else if(mid>0 && arr[mid]<arr[mid-1])
    {
        return peak_element(arr,low,mid-1,n);
    }
    
    else
    {
        return peak_element(arr,mid+1,high,n);
    }
}

int main()
{
    int arr[]={0,6,8,5,7,9};
    int n=7;
    cout<<"peak element in array:"<<peak_element(arr,0,n-1,n);
    return 0;
}