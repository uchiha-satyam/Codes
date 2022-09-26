class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        for(int i=m; i>=0; i--)
        {
            for(int j=n; j>=0; j--)
            {
                if(i==m||j==n)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(text1[i]==text2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};