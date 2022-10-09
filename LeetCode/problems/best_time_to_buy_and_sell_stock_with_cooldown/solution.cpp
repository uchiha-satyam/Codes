class Solution {
public:

    // int mp(vector<int>& prices, int i, bool buy)
    // {
    //     int n = prices.size();
    //     if(i>=n) return 0;
    //     if(buy)
    //     {
    //         return max( - prices[i] + mp(prices,i+1,false), mp(prices,i+1,true));
    //     }
    //     else
    //     {
    //         return max( + prices[i] + mp(prices,i+2,true), mp(prices,i+1,false));
    //     }
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+2][2];
        dp[n+1][0] = dp[n+1][1] = 0;
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                if(j==0)
                {
                    dp[i][j] = max( - prices[i] + dp[i+1][1], dp[i+1][0] );
                }
                else
                {
                    dp[i][j] = max( + prices[i] + dp[i+2][0], dp[i+1][1] );
                }
            }
        }
        return dp[0][0];
        // return mp(prices,0,true);
    }
};