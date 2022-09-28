class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n+1][n+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(j>i) continue;
                if(j==0)
                {
                    string s(i,'(');
                    dp[i][j].push_back(s);
                }
                else
                {
                    for(auto &x : dp[i][j-1])
                    {
                        dp[i][j].push_back(x+')');
                    }
                    for(auto &x : dp[i-1][j])
                    {
                        dp[i][j].push_back(x+'(');
                    }
                }
            }
        }
        return dp[n][n];
    }
};