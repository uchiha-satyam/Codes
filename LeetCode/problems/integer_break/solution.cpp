class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<=n; i++)
        {
            dp[i] = 0;
            for(int j=1; j<=i/2; j++)
            {
                int x = max(j,dp[j]);
                int y = max(i-j,dp[i-j]);
                dp[i] = max(dp[i],x*y);
            }
        }
        return dp[n];
    }
};