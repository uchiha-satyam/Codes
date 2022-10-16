class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        int maxVal;
        for(int j=0; j<n; j++)
        {
            // maxVal = 0;
            for(int i=n-1; i>=0; i--)
            {
                if(j<i) dp[i][j] = 0;
                else if(i==j) dp[i][j] = 1;
                else if(s[i]==s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                // maxVal = max(maxVal,dp[i][j]);
                // if(j+1<n)
                // dp[i][j+1] = maxVal;
            }
        }
        return dp[0][n-1];
    }
};