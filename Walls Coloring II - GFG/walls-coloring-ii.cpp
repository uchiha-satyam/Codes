//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(n,vector<int>(k));
        dp[0] = costs[0];
        int m = INT_MAX, pm = INT_MAX;
        for(int i=0; i<k; i++)
        {
            if(dp[0][i]<=m)
            {
                pm = m;
                m = dp[0][i];
            }
            else if(dp[0][i]<=pm)
            {
                pm = dp[0][i];
            }
        }
        for(int i=1; i<n; i++)
        {
            int nm = INT_MAX, npm = INT_MAX;
            for(int j=0; j<k; j++)
            {
                int cost;
                if(m==INT_MAX||pm==INT_MAX) return -1;
                if(dp[i-1][j]==m) cost = pm;
                else cost = m;
                dp[i][j] = costs[i][j] + cost;
                if(dp[i][j]<=nm)
                {
                    npm = nm;
                    nm = dp[i][j];
                }
                else if(dp[i][j]<=npm)
                {
                    npm = dp[i][j];
                }
            }
            m = nm;
            pm = npm;
        }
        // int ans = INT_MAX;
        // for(int i=0; i<k; i++)
        // ans = min(ans,dp[n-1][i]);
        return m;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends