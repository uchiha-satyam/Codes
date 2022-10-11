class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        sort(coins.begin(),coins.end());
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1; i<=amount; i++)
        {
            int req = INT_MAX;
            for(int j=m-1; j>=0; j--)
            {
                if(i>=coins[j] && dp[i-coins[j]]!=-1)
                {
                    req = min(req,1+dp[i-coins[j]]);
                }
            }
            if(req==INT_MAX) dp[i] = -1;
            else dp[i] = req;
        }
        return dp[amount];
    }
};