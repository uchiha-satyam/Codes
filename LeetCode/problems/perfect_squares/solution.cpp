class Solution {
public:
    int numSquares(int n) {
        vector<int> data;
        vector<int> dp(n+1,INT_MAX);
        for(int i=1; i<=sqrt(n); i++)
        {
            data.push_back(i*i);
            dp[i*i] = 1;
        }
        dp[0] = 0;
        for(int i=2; i<=n; i++)
        {
            if(dp[i] == 1) continue;
            // dp[i] = INT_MAX;
            for(int j=0; j<data.size() && data[j]<i; j++)
            {
                dp[i] = min(dp[data[j]]+dp[i-data[j]],dp[i]);
                // cout<<data[j]<<" "<<dp[data[j]]<<" "<<i-data[j]<<" "<<dp[i-data[j]]<<endl;
            }
        }
        return dp[n];
    }
};