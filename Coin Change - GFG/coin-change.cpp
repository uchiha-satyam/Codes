//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long>> dp(sum+1,vector<long long>(N,0));
        for(int i=0; i<N; i++)
        dp[0][i] = 1;
        sort(coins,coins+N);
        for(int i=1; i<=sum; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(j!=0) dp[i][j] = dp[i][j-1];
                if(i>=coins[j]) dp[i][j] += dp[i-coins[j]][j];
            }
        }
        return dp[sum][N-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends