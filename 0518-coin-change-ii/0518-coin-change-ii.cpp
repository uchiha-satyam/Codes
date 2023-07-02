class Solution {
    int help(vector<int>& coins, int amount, int idx, int& n, vector<vector<int>>& dp)
    {
        if(amount==0) return 1;
        int ans = 0;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        for(int i=idx; i<n; i++)
        {
            if(amount-coins[i]<0) break;
            ans += help(coins,amount-coins[i],i,n,dp);
        }
        return dp[amount][idx] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,0));
        // return help(coins,amount,0,n,dp);
        for(int i=0; i<n; i++)
            dp[0][i] = 1;
        int sum = -1;
        for(int i=1; i<=amount; i++)
        {
            sum = -1;
            for(int j=0; j<n; j++)
            {
                if(sum!=-1)
                {
                    if(i-coins[j-1]<0) break;;
                    dp[i][j] = sum - dp[i-coins[j-1]][j-1];
                    sum = dp[i][j];
                }
                else
                {
                    for(int k=j; k<n; k++)
                    {
                        if(i-coins[k]<0) break;
                        dp[i][j] += dp[i-coins[k]][k];
                    }
                    sum = dp[i][j];
                }
            }
        }
        return dp[amount][0];
    }
};