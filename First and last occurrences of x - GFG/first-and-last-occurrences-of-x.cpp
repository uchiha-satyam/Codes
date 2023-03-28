//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> pos;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==x)
        {
            if(pos.empty()||pos.size()==1) pos.push_back(i);
            else pos.back() = i;
        }
    }
    if(pos.size()==1) pos.push_back(pos.back());
    if(pos.empty())
    {
        pos.push_back(-1);
        pos.push_back(-1);
    }
    return pos;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends