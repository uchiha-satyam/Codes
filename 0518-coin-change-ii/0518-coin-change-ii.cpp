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
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        return help(coins,amount,0,n,dp);
    }
};