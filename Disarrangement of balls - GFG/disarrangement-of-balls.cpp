//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long int disarrange(int N){
        // code here
        long long dp[N+1], mod = 1e9+7;
        dp[0] = 1;
        dp[1] = 0;
        for(int i=2; i<=N; i++)
        {
            dp[i] = ((i-1)%mod)*(((dp[i-2]%mod)+(dp[i-1]%mod))%mod);
        }
        return dp[N]%mod;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends