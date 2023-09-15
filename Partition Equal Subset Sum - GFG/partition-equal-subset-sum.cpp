//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum%2) return false;
        sum /= 2;
        bool dp[N][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(j==0) dp[i][j] = true;
                else if(i==0)
                {
                    if(j==arr[i]) dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                    if(j>=arr[i]) dp[i][j] = dp[i][j]||dp[i-1][j-arr[i]];
                }
            }
        }
        return dp[N-1][sum];
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends