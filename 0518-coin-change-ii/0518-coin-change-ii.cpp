class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        int dp[amount+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        dp[0][i] = 1;
        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i-coins[j]<0) break;
                dp[i][j] = dp[i-coins[j]][j];
            }
            for(int j=1; j<n; j++)
            dp[i][j] += dp[i][j-1];
        }
        return dp[amount][n-1];
    }
};