//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    pair<int,pair<int,int>> traverse(int arr[], int l, int r, vector<vector<pair<int,pair<int,int>>>>& dp)
    {
        if(l==r) return {0,{arr[l-1],arr[r]}};
        if(dp[l][r].first!=-1) return dp[l][r];
        pair<int,pair<int,int>> ans = {INT_MAX,{-1,-1}};
        for(int i=l; i<r; i++)
        {
            pair<int,pair<int,int>> p1 = traverse(arr,l,i,dp);
            pair<int,pair<int,int>> p2 = traverse(arr,i+1,r,dp);
            if(p1.first+p2.first+p1.second.first*p1.second.second*p2.second.second < ans.first)
            {
                ans.first = p1.first+p2.first+p1.second.first*p1.second.second*p2.second.second;
                ans.second.first = p1.second.first;
                ans.second.second = p2.second.second;
            }
            else if(p1.first+p2.first+p1.second.first*p1.second.second*p2.second.second == ans.first)
            {
                if(p1.second.first*p2.second.second<ans.second.first*ans.second.first)
                {
                    ans.second.first = p1.second.first;
                    ans.second.second = p2.second.second;
                }
            }
        }
        dp[l][r] = ans;
        return ans;
    }
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<pair<int,pair<int,int>>>> dp(n,vector<pair<int,pair<int,int>>>(n,{-1,{-1,-1}}));
        return traverse(arr,1,n-1,dp).first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends