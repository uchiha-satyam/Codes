//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        long long dp[n+1];
        dp[1] = dp[2] = 1;
        long long mod = 1e9+7;
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-2] + dp[i-1];
            dp[i] %= mod;
        }
        return (int)dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends