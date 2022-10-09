class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n+1][2];
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                if(j==0)
                {
                    dp[i][j] = max( - prices[i] - fee + dp[i+1][1], dp[i+1][0] );
                }
                else
                {
                    dp[i][j] = max( + prices[i] + dp[i+1][0], dp[i+1][1] );
                }
            }
        }
        return dp[0][0];
    }
};