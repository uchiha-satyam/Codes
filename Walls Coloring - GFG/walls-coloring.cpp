//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp(3,vector<int>(N+1,INT_MAX));
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[2][0] = 0;
        for(int i=1; i<=N; i++)
        {
            dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + colors[i-1][0];
            dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + colors[i-1][1];
            dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + colors[i-1][2];
        }
        return min(dp[0][N],min(dp[1][N],dp[2][N]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends