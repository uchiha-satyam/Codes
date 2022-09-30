class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v(5,1);
        vector<vector<int>> dp(n+1,v);
        int sum = 5;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(j==0)
                {
                    dp[1][j] = sum;
                    sum = 0;
                }
                else dp[1][j] = dp[1][j-1] - dp[0][j-1];
                // cout<<dp[i][j]<<" ";
                sum += dp[1][j];
            }
            dp.erase(dp.begin());
            // cout<<endl;
        }
        return dp[0][0];
    }
};