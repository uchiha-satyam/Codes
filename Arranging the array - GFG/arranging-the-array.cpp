//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends

void dosomething(int arr[], int l, int r)
{
    if(l>=r) return;
    int neg = 0;
    for(int i=l; i<=r; i++)
    {
        if(arr[i]<0) neg++;
    }
    if(neg==0||neg==r-l+1) return;
    dosomething(arr,l,l+neg-1);
    dosomething(arr,l+neg,r);
    int p = l+neg;
    for(int i=l; i<l+neg; i++)
    {
        if(arr[i]>=0)
        {
            swap(arr[i],arr[p]);
            p++;
        }
    }
}
void Rearrange(int arr[], int n)
{
    // Your code goes here
    dosomething(arr,0,n-1);
}